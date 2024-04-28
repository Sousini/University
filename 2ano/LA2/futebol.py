def tabela(jogos):
    #jogos = [("Benfica",3,"Porto",2),("Benfica",0,"Sporting",0),("Porto",4,"Benfica",1),("Sporting",2,"Porto",2)]
    TabDic = {} #EQUIPA:( PONTOS, NETGOALS)
    for jogo in jogos:
        
        #EMPATE 
        if jogo[1]==jogo[3]:
            for equipa in (jogo[0], jogo[2]):
                addPoints(TabDic, equipa, 1)
        
        #VITORIA (1)
        elif jogo[1]>jogo[3]:
            addPoints(TabDic, jogo[0], 3)

        #DERROTA (1)
        else: 
            addPoints(TabDic, jogo[2], 3)

        #ADICIONA DIFF GOLOS
        addNetGoals(TabDic, jogo)
    
    #SORT

    TabDic=list(sorted(TabDic.items(), key= lambda x: (-x[1][0],-x[1][1],x[0])))

    return [(element[0], element[1][0]) for element in TabDic]

def addPoints(TabDic, equipa, pontos):
    if equipa in TabDic:
        TabDic[equipa]=(TabDic[equipa][0]+pontos, TabDic[equipa][1])
    else:
        TabDic[equipa]=(pontos, 0)

def addNetGoals(TabDic, jogo):
    for equipaID in [0,2]:
        equipa=jogo[equipaID]
        if equipa in TabDic:
            TabDic[equipa]=(TabDic[equipa][0],TabDic[equipa][1]+(jogo[(equipaID+1)]-jogo[(equipaID+3)%4]))
            #print("Existe {} >> {}".format(equipa, TabDic[equipa]))
        else:
            TabDic[equipa]=(0, jogo[(equipaID+1)]-jogo[(equipaID+3)%4])