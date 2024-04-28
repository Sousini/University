def formata(codigo):
    #for i,letra in enumerate(codigo): nao passes isto ya?
    #    while (i<len(codigo)-1) and ((letra in [";"," "]) and codigo[i+1]==" "): nao passes isto ya?
    #        codigo = codigo[:i+1]+codigo[i+2:] nao passes isto ya?
    
    
    new_codigo = ""
    counter = 0
    for i,char in enumerate(codigo): # dar valores de indices a cada char 
        if char == '{':
            counter +=1
            new_codigo += '{\n'
            new_codigo += '  '*counter
            
        elif char == ';' and i<len(codigo)-2:
            new_codigo += ';\n'
            new_codigo += '  '*counter
        elif char == ";" and i==len(codigo)-2:
            new_codigo += ";\n"
        elif char == ' ' and codigo[i-1] == ' ':
            new_codigo += ''
        elif char == ' ' and codigo[i+1] == ' ':
            new_codigo += ''
        elif char == '}':
            counter-=1
            if i != len(codigo)-1:
                new_codigo += '}'
                new_codigo += '  '*counter
            else:
                new_codigo += "}"
        
        
        else:
            new_codigo += char

    return new_codigo