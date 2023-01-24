

-- Questão 1 

-- a 
 
any' :: (a -> Bool) -> [a] -> Bool  
any' _ [] = False 
any' p (h:t) = p h || any' p t  


-- b 

zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c] 
zipWith' _ _ [] = [] 
zipWith' _ [] _ = [] 
zipWith' f (h:t) (x:xs) = f h x : zipWith' f t xs 

-- c 

takeWhile' :: (a -> Bool) -> [a] -> [a] 
takeWhile' _ [] = [] 
takeWhile' f (h:t) = if f h then h : takeWhile' f t 
                   else []  

-- d 

dropWhile' :: (a -> Bool) -> [a] -> [a] 
dropWhile' _ [] = [] 
dropWhile' f (h:t) = if f h then dropWhile' f t 
                   else h:t 



-- e 

span' :: (a -> Bool) -> [a] -> ([a],[a]) 
span' _ [] = ([],[]) 
span' f (h:t) = if f h then (h:lt, ld) 
             else ([], h:t) 
          where (lt,ld) = span' f t 


-- f 

deleteBy' :: (a -> a -> Bool) -> a -> [a] -> [a] 
deleteBy' _ _ [] = [] 
deleteBy' f x (h:t) = if f x h then t
                   else h : deleteBy' f x t  


-- g 

sortOn' :: Ord b => (a -> b) -> [a] -> [a] 
sortOn' _ [] = [] 
sortOn' f (h:t) = aux f h (sortOn' f t)
                  where aux :: Ord b => (a -> b) -> a -> [a] -> [a]
                        aux f x [] = [x]
                        aux f x (a:b) = if f x > f a then a : aux f x b else x : a : b

-- Questão 2 

type Polinomio = [Monomio] 
type Monomio = (Float,Int) 

-- a 

selgrau :: Int -> Polinomio -> Polinomio 
selgrau n l = filter (\x -> snd x == n) l 


-- b 

--conta :: Int -> Polinomio -> Int 


-- c 

grau :: Polinomio -> Int 
grau p =  maximum (map snd p)

