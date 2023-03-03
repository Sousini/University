

-- Exercicio 2


-- alinea a 


dobros :: [Float] -> [Float]
dobros []    = [] 
dobros (h:t) = 2*h : dobros t  


-- alinea b 

numOcorre :: Char -> String -> Int 
numOcorre c [] = 0 
numOcorre c (h:t) = if c == h then 1 + numOcorre c t   
                    else numOcorre c t


-- alinea c

positivos :: [Int] -> Bool 
positivos [x] = x >= 0
positivos (h:t) = if h >= 0 then positivos t 
                  else False 


-- alinea d 

soPos :: [Int] -> [Int] 
soPos [] = [] 
soPos (h:t) = if h > 0 then h : soPos t 
              else soPos t 


-- alinea e 

somaNeg :: [Int] -> Int 
somaNeg [] = 0  
somaNeg (h:t) = if h < 0 then h + somaNeg t 
                else somaNeg t 
 

-- alinea f 

tresUlt :: [a] -> [a] 
tresUlt [] = [] 
tresUlt (h:t) | length (h:t) <= 3 = (h : t) 
              | otherwise         = tresUlt t  


-- alinea g 

segundos :: [(a,b)] -> [b] 
segundos [] = [] 
segundos ((x,y) : t) = y : segundos t  


-- alinea h 









-- alinea i 

sumTriplos :: (Num a, Num b, Num c) => [(a,b,c)] -> (a,b,c) 
sumTriplos [(a,b,c)] = (a,b,c) 
sumTriplos ((a,b,c):t) = let (a', b', c') = sumTriplos t
                         in (a+a',b+b',c+c') 





