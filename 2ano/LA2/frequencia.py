'''
Neste problem pretende-se que defina uma função que, dada uma string com palavras, 
devolva uma lista com as palavras nela contidas ordenada por ordem de frequência,
da mais alta para a mais baixa. Palavras com a mesma frequência devem ser listadas 
por ordem alfabética.
'''

def frequencia(texto):
    frequencias = {}

    palavras = texto.split()

    for palavra in palavras:
        frequencias[palavra] = frequencias.get(palavra, 0) + 1
    
    palavras_ordenadas = sorted(frequencias.keys(), key=lambda x: (-frequencias[x], x) )
    return palavras_ordenadas    