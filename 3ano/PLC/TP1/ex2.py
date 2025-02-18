# Rafael Cunha Costa A102526
# João Afonso Almeida Sousa A102462
# João Pedro Ribeiro Matos A102528

import re
import json
from htmlex2 import salvarhtml

total = 0

#0:_id 1:index 2:dataEMD 3:nome/primeiro 4:nome/último 5:idade 6:género 7:morada 8:modalidade 9:clube 10:email 11:federado 12:aprovado
atletas = []

maxidade = 0
minidade = -1

numgeneros = {
    'M': 0,
    'F': 0
}

modalidadesporano = {}

modalidades = {}

aptosporano = {}

nomestrocados = []

with open('emd.csv', 'r') as file:
    next(file)
    for line in file:
        total += 1
        atleta = re.findall(r'([^,]+)(?=,|$)',line)
        atleta[-1] = atleta[-1].strip()
        atletas.append(atleta)

        #maxidade e minidade
        idade = int(atleta[5])
        if idade > maxidade:
            maxidade = idade
        if minidade == -1 or idade < minidade:
            minidade = idade
        
        #Contagem de géneros
        genero = atleta[6]
        numgeneros[genero] += 1

        data = atleta[2]
        ano = int(re.match(r'([0-9]{4})-[0-9]{2}-[0-9]{2}', data).group(1))
        modalidade = atleta[8]
        if ano not in modalidadesporano:
            modalidadesporano[ano] = {}
        if modalidade not in modalidadesporano[ano]:
            modalidadesporano[ano][modalidade] = 1
        else:
            modalidadesporano[ano][modalidade] += 1
        if modalidade not in modalidades:
            modalidades[modalidade] = 1
        else:
            modalidades[modalidade] += 1
        
        apto = atleta[12]
        if ano not in aptosporano:
            aptosporano[ano] = {'aptos': 0, 'nao_aptos': 0}
        if apto == 'true':
            aptosporano[ano]['aptos'] += 1
        else:
            aptosporano[ano]['nao_aptos'] += 1

        # Normalização de nomes
        if genero == 'M':
            nomestrocados.append(atleta)


if salvarhtml(minidade,maxidade,numgeneros,modalidades,modalidadesporano,aptosporano,nomestrocados,total) == 200:
    print("Relatório salvo em 'relatorio.html'")

with open('nomes_trocados.json', 'w', encoding='utf-8') as json_file:
    json.dump(nomestrocados, json_file, ensure_ascii=False, indent=4)
    print("Nomes trocados salvos em 'nomes_trocados.json'")