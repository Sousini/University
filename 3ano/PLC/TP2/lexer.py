from ply import lex

tokens = (
    # Reserved words
    'INT', 'MAIN', 'IF', 'ELSE', 'WHILE', 'READ', 'PRINT',
    
    # Identifiers and numbers
    'ID', 'NUMBER',
    
    # Operators
    'PLUS', 'MINUS', 'TIMES', 'DIVIDE', 'MODULO',
    'LT', 'GT', 'LE', 'GE', 'EQ', 'NE',
    'AND', 'OR', 'NOT',
    
    # Delimiters
    'LPAREN', 'RPAREN',
    'LBRACE', 'RBRACE',
    'LBRACKET', 'RBRACKET',
    'SEMICOLON',
    'EQUALS',
)

t_PLUS    = r'\+'
t_MINUS   = r'-'
t_TIMES   = r'\*'
t_DIVIDE  = r'/'
t_MODULO  = r'%'
t_LT      = r'<'
t_GT      = r'>'
t_LE      = r'<='
t_GE      = r'>='
t_EQ      = r'=='
t_NE      = r'!='
t_AND     = r'&&'
t_OR      = r'\|\|'
t_NOT     = r'!'
t_LPAREN  = r'\('
t_RPAREN  = r'\)'
t_LBRACE  = r'\{'
t_RBRACE  = r'\}'
t_LBRACKET = r'\['
t_RBRACKET = r'\]'
t_SEMICOLON = r';'
t_EQUALS  = r'='

# Reserved words
reserved = {
    'int': 'INT',
    'main': 'MAIN',
    'if': 'IF',
    'else': 'ELSE',
    'while': 'WHILE',
    'read': 'READ',
    'print': 'PRINT',
}

def t_ID(t):
    r'[a-zA-Z][a-zA-Z0-9]*'
    t.type = reserved.get(t.value, 'ID')
    return t

def t_NUMBER(t):
    r'\d+'
    t.value = int(t.value)
    return t

# ignore spaces and tabs
t_ignore = ' \t'

# New line handling
def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)

def t_error(t):
    print(f"Illegal character '{t.value[0]}' at line {t.lexer.lineno}")
    t.lexer.skip(1)

lexer = lex.lex()

def test_lexer(data):
    lexer.input(data)
    while True:
        tok = lexer.token()
        if not tok:
            break
        print(tok)

if __name__ == '__main__':
    data = '''
    int main() {
        int x = 5;
        int p = 30;
        int arr [10];
        arr [2] = x + p;
        if (x > 0) {
            print(arr [2]);
        }
    }
    '''
    test_lexer(data)