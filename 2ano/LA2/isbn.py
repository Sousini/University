'''
Pretende-se que implemente uma função que detecte códigos ISBN inválidos. 
Um código ISBN é constituído por 13 digitos, sendo o último um digito de controlo.
Este digito de controlo é escolhido de tal forma que a soma de todos os digitos, 
cada um multiplicado por um peso que é alternadamente 1 ou 3, seja um múltiplo de 10.
A função recebe um dicionário que associa livros a ISBNs,
e deverá devolver a lista ordenada de todos os livros com ISBNs inválidos.
'''

def isbn(livros):

    invalido = []
    flag=1
    sorted(livros)
    for x in livros:
        sum=0
        flag=0
        for y in livros[x]:
            flag = 1-flag
            if flag == 1:
                sum=sum+(int(y))
            else:
                sum=sum+(3*int(y))
        print("{}      >>>      {}".format(sum,x))
        #print("{}<------flag 2 ".format(flag2))
        if (sum%10) != 0:
            invalido.append(x)
            print("Appended {}".format(x))
        

        
    invalido.sort()        
    return invalido

        