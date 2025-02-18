import sys
from ply import yacc
from lexer import tokens
import os

class Parser:
    tokens = tokens

    def __init__(self):
        self.parser = yacc.yacc(module=self)
        self.symbol_table = {}
        self.current_offset = 0
        self.label_counter = 0
        self.assembly = []
        self.declared_vars = set()
        self.scope_stack = []

    def p_program(self, p):
        '''program : INT MAIN LPAREN RPAREN LBRACE declarations statements RBRACE'''
        for statement in p[7]:
            self.handle_statement(statement)
        p[0] = 'START\n' + '\n'.join(self.assembly) + '\nSTOP'

    def p_declarations(self, p):
        '''declarations : declaration declarations
                       | empty'''
        pass

    def p_declaration(self, p):
        '''declaration : INT ID SEMICOLON
                    | INT ID EQUALS expression SEMICOLON
                    | INT ID LBRACKET NUMBER RBRACKET SEMICOLON
                    | INT ID LBRACKET NUMBER RBRACKET LBRACKET NUMBER RBRACKET SEMICOLON'''
        
        if p[2] in self.declared_vars:
            raise ValueError(f"Variable {p[2]} already declared")
        
        self.declared_vars.add(p[2])

        # Regular variable
        if len(p) == 4:
            self.symbol_table[p[2]] = {'offset': self.current_offset}
            self.emit('PUSHI', 0)
            self.emit('STOREG', self.current_offset)
            self.current_offset += 1

        # Array
        elif len(p) == 7:
            size = p[4]
            self.symbol_table[p[2]] = {'offset': self.current_offset, 'size': size, 'type': 'array'}
            for i in range(size):
                self.emit('PUSHI', 0)
                self.emit('STOREG', self.current_offset + i)
            self.current_offset += size

        # Matrix
        elif len(p) == 10:
            size1, size2 = p[4], p[7]
            size = size1 * size2
            self.symbol_table[p[2]] = {'offset': self.current_offset, 'size1': size1, 'size2': size2, 'type': 'matrix'}
            for i in range(size):
                self.emit('PUSHI', 0)
                self.emit('STOREG', self.current_offset + i)
            self.current_offset += size

        # Variable with initialization
        else:
            self.symbol_table[p[2]] = {'offset': self.current_offset}
            self.handle_expression(p[4])
            self.emit('STOREG', self.current_offset)
            self.current_offset += 1

    def p_statements(self, p):
        '''statements : statement
                    | statement statements'''
        if len(p) == 2:
            p[0] = [p[1]]
        else:
            p[0] = [p[1]] + p[2]

    def p_statement(self, p):
        '''statement : assignment SEMICOLON
                    | while_statement
                    | if_statement
                    | io_statement SEMICOLON'''
        p[0] = p[1]

    def p_assignment(self, p):
        '''assignment : variable EQUALS expression'''
        p[0] = ('Assignment', p[1], p[3])

    def handle_statement(self, node):
        if isinstance(node, tuple):
            if node[0] == 'Assignment':
                self.handle_assignment(node)
            elif node[0] == 'While':
                self.handle_while(node)
            elif node[0] == 'If':
                self.handle_if(node)
            elif node[0] == 'Print':
                self.handle_print(node)
            elif node[0] == 'Read':
                self.handle_read(node)

    def handle_assignment(self, node):
        _, var, expr = node
        if isinstance(var, tuple):
            if var[0] == 'Variable':
                var_name = var[1]
                if var_name in self.symbol_table:
                    var_info = self.symbol_table[var_name]
                    self.handle_expression(expr)
                    self.emit('STOREG', var_info['offset'])
                else:
                    raise ValueError(f"Undefined variable: {var_name}")
            elif var[0] == 'ArrayAccess':
                self.handle_array_assignment(var, expr)

    def handle_array_assignment(self, var_node, expr_node):
        array_name = var_node[1]
        if array_name not in self.symbol_table:
            raise ValueError(f"Undefined array: {array_name}")
        
        array_info = self.symbol_table[array_name]
        base_offset = array_info['offset']

        # Push base address
        self.emit('PUSHGP')
        self.emit('PUSHI', base_offset)
        
        # Handle index
        if len(var_node) == 3:  # Array
            self.handle_expression(var_node[2])
        else:  # Matrix
            size2 = array_info['size2']
            self.handle_expression(var_node[2])  # First index
            self.emit('PUSHI', size2)
            self.emit('MUL')
            self.handle_expression(var_node[3])  # Second index
            self.emit('ADD')
        
        self.emit('ADD')
        self.handle_expression(expr_node)
        self.emit('STOREN')

    def p_while_statement(self, p):
        '''while_statement : WHILE LPAREN condition RPAREN LBRACE statements RBRACE'''
        p[0] = ('While', p[3], p[6])

    def handle_while(self, node):
        _, condition, statements = node
        start_label = self.new_label()
        end_label = self.new_label()

        self.emit(f'{start_label}:', 'NOP')
        self.handle_condition(condition)
        self.emit('JZ', end_label)

        for statement in statements:
            self.handle_statement(statement)

        self.emit('JUMP', start_label)
        self.emit(f'{end_label}:', 'NOP')

    def p_if_statement(self, p):
        '''if_statement : IF LPAREN condition RPAREN LBRACE statements RBRACE
                    | IF LPAREN condition RPAREN LBRACE statements RBRACE ELSE LBRACE statements RBRACE'''
        if len(p) == 8:
            p[0] = ('If', p[3], p[6], None)
        else:
            p[0] = ('If', p[3], p[6], p[10])

    def handle_if(self, node):
        _, condition, if_statements, else_statements = node
        else_label = self.new_label()
        end_label = self.new_label()

        self.handle_condition(condition)
        
        if else_statements:
            self.emit('JZ', else_label)
            for statement in if_statements:
                self.handle_statement(statement)
            self.emit('JUMP', end_label)
            self.emit(f'{else_label}:', 'NOP')
            for statement in else_statements:
                self.handle_statement(statement)
        else:
            self.emit('JZ', end_label)
            for statement in if_statements:
                self.handle_statement(statement)

        self.emit(f'{end_label}:', 'NOP')

    def p_io_statement(self, p):
        '''io_statement : READ LPAREN variable RPAREN
                    | PRINT LPAREN expression RPAREN'''
        if p[1] == 'read':
            p[0] = ('Read', p[3])
        else:
            p[0] = ('Print', p[3])

    def handle_print(self, node):
        self.handle_expression(node[1])
        self.emit('WRITEI')
        self.emit('WRITELN')

    def handle_read(self, node):
        self.emit('READ')
        self.emit('ATOI')
        self.handle_variable(node[1])

    def p_condition(self, p):
        '''condition : expression rel_op expression
                    | condition AND condition
                    | condition OR condition
                    | NOT condition
                    | LPAREN condition RPAREN'''
        if len(p) == 4:
            if p[2] in ['&&', '||']:
                p[0] = ('LogicalOp', p[2], p[1], p[3])
            else:
                p[0] = ('Condition', p[2], p[1], p[3])
        elif len(p) == 3:
            p[0] = ('Not', p[2])
        else:
            p[0] = p[2]

    def handle_condition(self, node):
        if node[0] == 'Condition':
            op, left, right = node[1], node[2], node[3]
            self.handle_expression(left)
            self.handle_expression(right)
            if op == '<':
                self.emit('INF')
            elif op == '>':
                self.emit('SUP')
            elif op == '<=':
                self.emit('INFEQ')
            elif op == '>=':
                self.emit('SUPEQ')
            elif op == '==':
                self.emit('EQUAL')
            elif op == '!=':
                self.emit('EQUAL')
                self.emit('NOT')
        elif node[0] == 'LogicalOp':
            self.handle_logical_op(node)
        elif node[0] == 'Not':
            self.handle_condition(node[1])
            self.emit('NOT')

    def handle_logical_op(self, node):
        op, left, right = node[1], node[2], node[3]
        if op == '&&':
            end_label = self.new_label()
            self.handle_condition(left)
            self.emit('JZ', end_label)
            self.handle_condition(right)
            self.emit(f'{end_label}:', 'NOP')
        elif op == '||':
            true_label = self.new_label()
            end_label = self.new_label()
            self.handle_condition(left)
            self.emit('JNZ', true_label)
            self.handle_condition(right)
            self.emit('JUMP', end_label)
            self.emit(f'{true_label}:', 'PUSHI 1')
            self.emit(f'{end_label}:', 'NOP')

    def p_expression(self, p):
        '''expression : term
                     | expression PLUS term
                     | expression MINUS term'''
        if len(p) == 2:
            p[0] = p[1]
        else:
            p[0] = ('BinOp', p[2], p[1], p[3])

    def handle_expression(self, node):
        if isinstance(node, tuple):
            if node[0] == 'BinOp':
                self.handle_binop(node)
            elif node[0] == 'Number':
                self.emit('PUSHI', node[1])
            elif node[0] == 'Variable':
                self.handle_variable(node)
            elif node[0] == 'ArrayAccess':
                self.handle_array_access(node)

    def handle_binop(self, node):
        _, op, left, right = node
        self.handle_expression(left)
        self.handle_expression(right)
        if op == '+':
            self.emit('ADD')
        elif op == '-':
            self.emit('SUB')
        elif op == '*':
            self.emit('MUL')
        elif op == '/':
            self.emit('DIV')
        elif op == '%':
            self.emit('MOD')

    def handle_variable(self, node):
        var_name = node[1]
        if var_name in self.symbol_table:
            var_info = self.symbol_table[var_name]
            self.emit('PUSHG', var_info['offset'])
        else:
            raise ValueError(f"Undefined variable: {var_name}")

    def handle_array_access(self, node):
        array_name = node[1]
        if array_name not in self.symbol_table:
            raise ValueError(f"Undefined array: {array_name}")
        
        array_info = self.symbol_table[array_name]
        base_offset = array_info['offset']

        self.emit('PUSHGP')
        self.emit('PUSHI', base_offset)
        
        if len(node) == 3:  # Array
            self.handle_expression(node[2])
        else:  # Matrix
            size2 = array_info['size2']
            self.handle_expression(node[2])
            self.emit('PUSHI', size2)
            self.emit('MUL')
            self.handle_expression(node[3])
            self.emit('ADD')
        
        self.emit('ADD')
        self.emit('LOADN')

    def p_term(self, p):
        '''term : factor
                | term TIMES factor
                | term DIVIDE factor
                | term MODULO factor'''
        if len(p) == 2:
            p[0] = p[1]
        else:
            p[0] = ('BinOp', p[2], p[1], p[3])

    def p_factor(self, p):
        '''factor : NUMBER
                | variable
                | LPAREN expression RPAREN'''
        if len(p) == 2:
            if isinstance(p[1], int):
                p[0] = ('Number', p[1])
            else:
                p[0] = p[1]
        else:
            p[0] = p[2]

    def p_variable(self, p):
        '''variable : ID
                   | ID LBRACKET expression RBRACKET
                   | ID LBRACKET expression RBRACKET LBRACKET expression RBRACKET'''
        if len(p) == 2:
            p[0] = ('Variable', p[1])
        elif len(p) == 5:
            p[0] = ('ArrayAccess', p[1], p[3])
        else:
            p[0] = ('ArrayAccess', p[1], p[3], p[6])

    def p_rel_op(self, p):
        '''rel_op : LT
                 | GT
                 | LE
                 | GE
                 | EQ
                 | NE'''
        p[0] = p[1]

    def p_empty(self, p):
        'empty :'
        pass

    def p_error(self, p):
        if p:
            print(f"Syntax error at '{p.value}', line {p.lineno}")
        else:
            print("Syntax error at EOF")

    def new_label(self):
        self.label_counter += 1
        return f'L{self.label_counter}'

    def emit(self, *args):
        self.assembly.append(' '.join(str(arg) for arg in args))

    def save_to_file(self, filename):
        with open(filename, "w") as f:
            f.write("\n".join(self.assembly))
    

    # Others

    def p_expression(self, p):
        '''expression : term
                     | expression PLUS term
                     | expression MINUS term
                     | expression rel_op term'''
        if len(p) == 2:
            p[0] = p[1]
        else:
            p[0] = ('BinOp', p[2], p[1], p[3])

    def p_term(self, p):
        '''term : factor
                | term TIMES factor
                | term DIVIDE factor
                | term MODULO factor'''
        if len(p) == 2:
            p[0] = p[1]
        else:
            p[0] = ('BinOp', p[2], p[1], p[3])

    def p_factor(self, p):
        '''factor : NUMBER
                | variable
                | LPAREN expression RPAREN'''
        if len(p) == 2:  # NUMBER or variable
            if isinstance(p[1], int):
                p[0] = ('Number', p[1])
            else:
                p[0] = p[1]  # variable is already a tuple
        else:  # LPAREN expression RPAREN
            p[0] = p[2]

    def p_variable(self, p):
        '''variable : ID
                   | ID LBRACKET expression RBRACKET
                   | ID LBRACKET expression RBRACKET LBRACKET expression RBRACKET'''
        
        # Variable
        if len(p) == 2:
            p[0] = ('Variable', p[1])
        
        # Array element
        elif len(p) == 5:
            p[0] = ('ArrayAccess', p[1], p[3])
        
        # Matrix element
        else:
            p[0] = ('ArrayAccess', p[1], p[3], p[6])


    def p_rel_op(self, p):
        '''rel_op : LT
                 | GT
                 | LE
                 | GE
                 | EQ
                 | NE'''
        p[0] = p[1]

    def p_empty(self, p):
        'empty :'
        pass


def compile_code(source_code, input_filepath):
    parser = Parser()
    parser.parser.parse(source_code)
    
    dir_path = os.path.dirname(input_filepath)
    base_name = os.path.splitext(os.path.basename(input_filepath))[0]
    output_path = os.path.join(dir_path, f"{base_name}.vm")
    
    parser.save_to_file(output_path)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python parser.py <source_file>")
        sys.exit(1)

    input_path = sys.argv[1]

    if not os.path.exists(input_path):
        print(f"Error: File '{input_path}' not found.")
        sys.exit(1)

    with open(input_path, "r") as file:
        source_code = file.read()

    compile_code(source_code, input_path)
    print(f"Compiled assembly saved to {os.path.splitext(input_path)[0]}.vm")