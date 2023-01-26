

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

conta :: Int -> Polinomio -> Int 
conta n l = foldr (\x conta -> if n == snd x then conta + 1 else conta) 0 l  


-- c 

grau :: Polinomio -> Int 
grau p = maximum (map snd p) 


-- d 

deriv :: Polinomio -> Polinomio 
deriv p = let l = map (\(x,y) -> if y > 0 then (x*fromIntegral (y), y-1) else (0,0)) p
          in filter (/= (0,0)) l  


-- e 

calcula :: Float -> Polinomio -> Float
calcula n p = foldr (\(x,y) acc -> if x /= 0 then (x*(n)^y) + acc else 0) 0 p


-- f 

simp :: Polinomio -> Polinomio 
simp p = filter (\x -> fst x/= 0) p 


-- g 

mult :: Monomio -> Polinomio -> Polinomio 
mult (c,e) p = map (\(c2,e2) -> (c*c2,e+e2)) p  


-- h 

ordena :: Polinomio -> Polinomio 
ordena p = sortOn' snd p 



-- i ?? 

normaliza :: Polinomio -> Polinomio 
normaliza l = let x = fromIntegral $ grau l in [ ((a/x),b) | (a,b) <- l]


-- j ??

soma :: Polinomio -> Polinomio -> Polinomio 
soma pol1 pol2 = normaliza $ (++) pol1 pol2 
--soma l p = normaliza ((++) l p ) 


-- k 

produto :: Polinomio -> Polinomio -> Polinomio 
produto pol1 pol2 = foldr mult pol1 pol2 


-- l 

equiv :: Polinomio -> Polinomio -> Bool 
equiv pol1 pol2 = ordena(normaliza pol1) == ordena (normaliza pol2) 


-- Questão 3 

type Mat a = [[a]] 

-- a 

dimOK :: Mat a -> Bool 
dimOK (m:t) = all (\l1 -> length m == length l1) t   


-- b 

dimMat :: Mat a -> (Int,Int) 
dimMat (m:t) = (length m, length (m:t)) 


-- c 

addMat :: Num a => Mat a -> Mat a -> Mat a 
addMat m1 m2= zipWith' (\l1 l2 -> zipWith' (+) l1 l2) m1 m2 


-- d 

transpose' :: Mat a -> Mat a 
transpose' ([]:_) = []  
transpose' m = let l = map head m 
                   p = map tail m 
               in l : transpose' p  



-- e 

multMat :: Num a => Mat a -> Mat a -> Mat a 
multMat m1 m2 = zipWith' (\l1 l2 -> zipWith' (*) l1 l2) m1 m2 



-- f 

zipWMat :: (a -> b -> c) -> Mat a -> Mat b -> Mat c 
zipWMat f m1 m2 = zipWith' (\l1 l2 -> zipWith' f l1 l2) m1 m2  