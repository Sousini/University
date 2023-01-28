

-- Questão 1 

data Frac = F Integer Integer 


-- a 
 
normaliza :: Frac -> Frac 
normaliza (F 0 x) = F 0 1 
normaliza (F x y) = let md = mdc (abs x) (abs y) 
                        sinal = if x*y > 0 then 1 else (-1)  
                    in F (sinal * (div (abs x) md)) (div (abs y) md)  


mdc :: Integer -> Integer -> Integer 
mdc x y | x == y = x 
        | x > y = mdc (x-y) y 
        | x < y = mdc x (y-x)   



-- b 

instance Eq Frac where 
    (==) (F n1 n2) (F n3 n4) = n1*n2 == n3*n4 



-- c 

instance Ord Frac where 
    compare (F n1 n2) (F n3 n4) | n1*n2 == n3*n4 = EQ 
                                | n1*n2 < n3*n4 = LT 
                                | n1*n2 > n3*n4 = GT  



-- d 

instance Show Frac where 
    show (F x 1) = show x 
    show (F x y) = show x ++ "/" ++ show y  



-- e 

instance Num Frac where 
    (+) (F n1 n2) (F n3 n4) = (F ((n1*n4) + (n2*n3)) (n2*n4)) 
    (*) (F n1 n2) (F n3 n4) = (F (n1*n3) (n2*n4)) 
    (-) (F n1 n2) (F n3 n4) = (F ((n1*n4)-(n2*n3)) (n2*n4)) 
    negate (F n1 n2) = normaliza (F (-n1) n2) 
    abs (F n1 n2) = (F (abs n1) (abs n2)) 
    signum (F n1 n2) | n1 == 0 = F 0 1 
                     | n1*n2 > 0 = F 1 1 
                     | n1*n2 < 0 = F (-1) 1 
    fromInteger n1 = F n1 1 



-- f 

seleciona2 :: Frac -> [Frac] -> [Frac] 
seleciona2 f l = filter (\j -> j > f*2 ) l  

