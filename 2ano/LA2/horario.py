"""

Implemente uma função que calcula o horário de uma turma de alunos.
A função recebe dois dicionários, o primeiro associa a cada UC o
respectivo horário (um triplo com dia da semana, hora de início e
duração) e o segundo associa a cada aluno o conjunto das UCs em
que está inscrito. A função deve devolver uma lista com os alunos que
conseguem frequentar todas as UCs em que estão inscritos, indicando
para cada um desses alunos o respecto número e o número total de horas
semanais de aulas. Esta lista deve estar ordenada por ordem decrescente
de horas e, para horas idênticas, por ordem crescente de número.

"""

def horario(ucs,alunos):
    nonCompSche = []
    #ucs = {"la2": ("quarta",16,2), "pi": ("terca",15,1), "cp": ("terca",14,2),"so": ("quinta",9,3)}
    #alunos = {5000: {"la2","cp"}, 2000: {"la2","cp","pi"},3000: {"cp","poo"}, 1000: {"la2","cp","so"}}
    for nAluno in list(alunos.keys()):
        print("Novo ALUNO {}".format(nAluno))
        cadeiraAux = []
        for i,cadeira in enumerate(alunos[nAluno]):
            if i == 0:
                cadeiraAux.append(cadeira)
            else:
                if verCompList(cadeiraAux, ucs, cadeira) == 1:
                    nonCompSche.append(nAluno)
                else:
                    cadeiraAux.append(cadeira)
    returnList = []
    for nAluno in list(alunos.keys()):
        if nAluno not in nonCompSche:
            returnList.append((nAluno, sumHoras(nAluno, ucs, alunos)))
    return sorted(returnList, key = lambda x: (-x[1],x[0]))

def verCompList(cadeiraAux, ucs, cadeira):
    for insche in cadeiraAux:
        if ((insche in list(ucs.keys())) and (cadeira in list(ucs.keys()))): #Not compatible
            if (verCompSing(insche, ucs, cadeira) == 1):
                return 1;
        else:
            return 1;
    return 0; #True

def verCompSing(insche, ucs, cadeira):
    cadeira1 = ucs[cadeira]
    cadeira2 = ucs[insche]
    if cadeira1[0] != cadeira2[0]: #Compatible
        return 0
    else:
        timespan1 = (cadeira1[1], cadeira1[1]+cadeira1[2])
        timespan2 = (cadeira2[1], cadeira2[1]+cadeira2[2])
        if timespan1[1]<=timespan2[0] or timespan2[1]<=timespan1[0]: #Compatible
            return 0
        else: #Not compatible
            return 1

def sumHoras(nAluno, ucs, alunos):
    cadeiras=alunos[nAluno]
    totalHoras = 0
    for cadeira in cadeiras:
        totalHoras+=ucs[cadeira][2]
    return totalHoras
