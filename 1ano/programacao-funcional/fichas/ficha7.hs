


-- Questão 1 

data ExpInt = Const Int
            | Simetrico ExpInt
            | Mais ExpInt ExpInt
            | Menos ExpInt ExpInt
            | Mult ExpInt ExpInt 


-- a 

calcula :: ExpInt -> Int 
calcula (Const x) = x  
calcula (Simetrico e) = - (calcula e) 
calcula (Mais e1 e2)  = calcula e1 + calcula e2 
calcula (Menos e1 e2) = calcula e1 - calcula e2
calcula (Mult e1 e2)  = calcula e1 * calcula e2 


-- b 

infixa :: ExpInt -> String  
infixa (Const x) = show x  
infixa (Simetrico e) = "-" ++ infixa e
infixa (Mais e1 e2)  = "(" ++ infixa e1 ++ "+" ++ infixa e2 ++ ")" 
infixa (Menos e1 e2) = "(" ++ infixa e1 ++ "-" ++ infixa e2 ++ ")" 
infixa (Mult e1 e2)  = "(" ++ infixa e1 ++ "*" ++ infixa e2 ++ ")" 


--c 

posfixa :: ExpInt -> String 
posfixa 