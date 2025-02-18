# Rafael Cunha Costa A102526
# João Afonso Almeida Sousa A102462
# João Pedro Ribeiro Matos A102528

import re
from htmlex1 import salvarhtml

processos = {}
processosporano = {}
nomesproprios = {}
apelidos = {}
recsportio = 0
pais = {}

with open('processos.txt', 'r') as file:
    with open('processos_NoReps.txt', 'w', encoding='utf-8') as output_file:
        linhasUnica = []
        next(file)
        for line in file:
            if line not in linhasUnica:
                line = line.strip()
                linhasUnica.append(line)
                output_file.write(line + '\n')

with open('processos_NoReps.txt', 'r') as file:
    for line in file:
        processo = re.findall(r'([^:]+)::([^:]+)::([^:]+)::([^:]+)?::([^:]+)?::([^:]+)?', line)[0]
        processos[processo[0]] = {
            'data': processo[1],
            'confessado': processo[2],
            'pai': processo[3],
            'mae': processo[4],
            'observacoes': processo[5]
        }
        ano = int(re.match(r'([0-9]{4})-[0-9]{2}-[0-9]{2}', processo[1]).group(1))
        if ano not in processosporano:
            processosporano[ano] = [processo[0]]
        elif processo[0] not in processosporano[ano]:
            processosporano[ano].append(processo[0])

        seculo = ano//100 + 1

        nproprio = re.match(r'([A-Za-z]+)[ ,]?.*', processo[2]).group(1)
        apelido_match = re.match(r'.*[ ,]([A-Za-z]+)', processo[2])
        apelido = apelido_match.group(1) if apelido_match else ""
        npropriopai = ""
        apelidopai = ""
        npropriomae = ""
        apelidomae = ""
        if processo[3]!="":
            npropriopai = re.match(r'([A-Za-z]+)[ ,]?.*', processo[3]).group(1)
            apelidopai_match = re.match(r'.*[ ,]([A-Za-z]+)', processo[3])
            apelidopai = apelido_match.group(1) if apelido_match else ""
            if processo[3] not in pais:
                pais[processo[3]] = [processo[2]]
            elif processo[2] not in pais[processo[3]]:
                pais[processo[3]].append(processo[2])

        if processo[4]!="":
            npropriomae = re.match(r'([A-Za-z]+)[ ,]?.*', processo[4]).group(1)
            apelidomae_match = re.match(r'.*[ ,]([A-Za-z]+)', processo[4])
            apelidomae = apelido_match.group(1) if apelido_match else ""
        
        if nproprio not in nomesproprios:
            nomesproprios[nproprio] = 1
        else:
            nomesproprios[nproprio] += 1
        if apelido not in apelidos:
            apelidos[apelido] = 1
        else:
            apelidos[apelido] += 1
        if npropriopai not in nomesproprios:
            nomesproprios[npropriopai] = 1
        else:
            nomesproprios[npropriopai] += 1
        if apelidopai not in apelidos:
            apelidos[apelidopai] = 1
        else:
            apelidos[apelidopai] += 1
        if npropriomae not in nomesproprios:
            nomesproprios[npropriomae] = 1
        else:
            nomesproprios[npropriomae] += 1
    
        if processo[5]!= "":
            tiomatch = re.search(r'Tio', processo[5])
            if tiomatch:
                recsportio += 1
        
if salvarhtml(processosporano, nomesproprios, apelidos, recsportio, pais) == 200:
    print("Relatório salvo em 'relatorio.html'")