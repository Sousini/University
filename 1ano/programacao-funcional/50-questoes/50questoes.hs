




-- exercicio 1
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{-# HLINT ignore "Use list literal" #-}
{-# HLINT ignore "Use foldr" #-}
{-# HLINT ignore "Redundant if" #-}
{-# OPTIONS_GHC -Wno-overlapping-patterns #-}
{-# HLINT ignore "Redundant bracket" #-}

myenumFromTo :: Int -> Int -> [Int] 
myenumFromTo x y | x >= y = x : []
                 | x < y = x : myenumFromTo (x+1) y
                 | otherwise = [] 




-- exercicio 2 

myenumFromThenTo :: Int -> Int -> Int -> [Int] 
myenumFromThenTo x y z | x == z = x : []
                       | x < y && x < z = x : myenumFromThenTo y ( y + ( y - x ) ) z
                       | otherwise = []
                       



-- exercicio 3 

(+++) :: [a] -> [a] -> [a] 
(+++) x [] = x 
(+++) [] x = x 
(+++) (x:xs) l = x : (+++) xs l 



-- exercicio 4 

(!!!) :: [a] -> Int -> a 
(!!!) (h:t) 0 = h 
(!!!) (h:t) n = (!!!) t (n-1)  

-- exercicio 5  

myreverse :: [a] -> [a] 
myreverse [] = [] 
myreverse (h:t) = myreverse t ++ [h] 


-- exercicio 6 

mytake :: Int -> [a] -> [a] 
mytake n [] = [] 
mytake n (h:t) = if n > 0 then h : mytake (n-1) t   
                 else []  


-- exercicio 7 

mydrop :: Int -> [a] -> [a] 
mydrop n [] = [] 
mydrop 0  l = l   
mydrop n (h:t) = if n > 0 then mydrop (n-1) t 
                 else h:t  


-- exercicio 8 

myzip :: [a] -> [b] -> [(a,b)] 
myzip l [] = []
myzip [] l = [] 
myzip (x:xs) (y:ys) = (x,y) : myzip xs ys 


-- exercicio 9 

myreplicate :: Int -> a -> [a] 
myreplicate 0 x = [] 
myreplicate n x = x : myreplicate (n-1) x 


-- exercicio 10

myintersperse :: a -> [a] -> [a] 
myintersperse x [] = [] 
myintersperse x [a] = [a]  
myintersperse x (h:t) = h : x : myintersperse x t 


-- exercicio 11 

mygroup :: Eq a => [a] -> [[a]] 
mygroup [] = [] 
mygroup [x] = [[x]] 
mygroup (h:t) = if h == x then (h:x:xs):y 
            else [h] : (x:xs) : y  
    where ((x:xs):y) = mygroup t





-- exercicio 12 

myconcat :: [[a]] -> [a] 
myconcat [] = [] 
myconcat (h:t) = h ++ myconcat t  


-- exercicio 13 

myinits :: [a] -> [[a]] 
myinits [] = [[]] 
myinits l = myinits (retiraUlt l) ++ [l]
 
retiraUlt :: [a] -> [a] 
retiraUlt [x] = [] 
retiraUlt (h:t) = h : retiraUlt t




-- exercicio 14 

mytails :: [a] -> [[a]] 
mytails [] = [[]] 
mytails l = l : mytails (retiraPrimeiro l) 

retiraPrimeiro :: [a] -> [a] 
retiraPrimeiro [] = [] 
retiraPrimeiro (h:t) = t  




-- exercicio 15

heads :: [[a]] -> [a] 
heads [] = []
heads ([]:t) = heads t 
heads ((x:xs):t) = x : heads t  


-- exercicio 16

total :: [[a]] -> Int 
total [] = 0 
total ([]:t) = total t 
total (h:t) = length h + total t 



-- exercicio 17 

myfun  :: [(a,b,c)] -> [(a,c)] 
myfun [] = [] 
myfun ((x,y,z):t) = (x,z) : myfun t 



-- exercicio 18

cola :: [(String, b ,c)] -> String 
cola [] = [] 
cola ((x,y,z):t) = x ++ cola t 


-- exercicio 19 

idade :: Int -> Int -> [(String, Int)] -> [String] 
idade n x [] = [] 
idade a i ((n,y):t) | (a-y) >= i = n : idade a i t 
                    | (a-y) <  i =     idade a i t 


-- exercicio 20

mypowerEnumFrom :: Int -> Int -> [Int] 
mypowerEnumFrom n m = if (m-1) == 0 then [1]
                    else mypowerEnumFrom n (m-1) ++ [n^(m-1)] 



-- exercicio 21 

myisPrime :: Int -> Bool 
myisPrime n = if numeroDivisores n 2 == 0 then True 
              else False 



numeroDivisores :: Int -> Int -> Int 
numeroDivisores n m | m >= n = 0
                    | mod n m == 0 = 1 
                    | otherwise = numeroDivisores n (m+1) 


-- execicio 22 

myisPrefixOf :: Eq a => [a] -> [a] -> Bool 
myisPrefixOf [] l = True
myisPrefixOf (x:xs) (h:t) = if x == h then myisPrefixOf xs t 
                            else False 


-- exercicio 23

myisSuffixOf :: Eq a => [a] -> [a] -> Bool 
myisSuffixOf [] [] = True 
myisSuffixOf [] l = False  
myisSuffixOf (x:xs) (h:t) = if x == h then myisSuffixOf xs t 
                          else myisSuffixOf (x:xs) t 
                     

-- exercicio 24  

myisSubsequenceOf :: Eq a => [a] -> [a] -> Bool 
myisSubsequenceOf [] l         = True
myisSubsequenceOf l []         = False
myisSubsequenceOf (x:xs) (h:t) = if x == h then myisSubsequenceOf xs t 
                                else myisSubsequenceOf (x:xs) t


-- exercicio 25 

myelemIndices :: Eq a => a -> [a] -> [Int] 
myelemIndices n [] = [] 
myelemIndices n l = aux'' 0 n l


aux'' :: Eq a => Int -> a -> [a] -> [Int] 
aux'' x n [] = [] 
aux'' x n (h:t) = if n == h then x : aux'' (x+1) n t 
              else aux'' (x+1) n t 



-- exercicio 26 

mynub :: Eq a => [a] -> [a] 
mynub [] = [] 
mynub (h:t) = if repete h t then mynub t 
            else h : mynub t 

repete :: Eq a => a -> [a] -> Bool 
repete n [] = False 
repete n (h:t) = if n == h then True 
               else repete n t


-- exercicio 27 

mydelete :: Eq a => a -> [a] -> [a] 
mydelete n [] = []
mydelete n (h:t) = if n == h then t 
                 else h : mydelete n t 


-- exercicio 28 

(\\\) :: Eq a => [a] -> [a] -> [a] 
(\\\) l [] = l 
(\\\) [] l = [] 
(\\\) (x:xs) (h:t) = (\\\) (delete2 h (x:xs)) t 


delete2 :: Eq a => a -> [a] -> [a] 
delete2 _ [] = [] 
delete2 n (h:t) = if n == h then t 
                else h : delete2 n t




-- exercicio 29 

myunion :: Eq a => [a] -> [a] -> [a] 
myunion [] l = l
myunion l [] = l 
myunion (h:t) (x:xs) = if ocorre x (h:t) then myunion (h:t) xs
                     else myunion (h:t) xs ++ [x]
 

ocorre :: Eq a => a -> [a] -> Bool 
ocorre _ [] = False
ocorre n (h:t) = if n == h then True 
               else ocorre n t 



-- exercicio 30 

myintersect :: Eq a => [a] -> [a] -> [a] 
myintersect [] l = [] 
myintersect l [] = [] 
myintersect (h:t) (x:xs) = if ocorre h (x:xs) then h : myintersect t (x:xs) 
                          else myintersect t (x:xs)  

 
   
-- exercicio 31 

myinsert :: Ord a => a -> [a] -> [a]
myinsert n [] = [n] 
myinsert n (h:t) = if n <= h then n : (h:t) 
                 else h : myinsert n t



-- exercicio 32

myunwords :: [String] -> String 
myunwords [] = [] 
myunwords [x] = x 
myunwords (h:t) = h ++ " " ++ myunwords t 


-- exercicio 33 

myunlines :: [String] -> String 
myunlines [] = [] 
myunlines [x] = x ++ "\n"
myunlines (h:t) = h ++ "\n" ++ myunlines t 



-- exercicio 34

mypMaior :: Ord a => [a] -> Int 
mypMaior (h:t) = aux''' h t 0 1  

aux''' :: Ord a => a -> [a] -> Int -> Int -> Int  
aux''' n [] x m = x  
aux''' n (h:t) x m = if h > n then aux''' h t m (m+1) 
                  else aux''' n t x (m+1)  
 


-- exercicio 35

mylookup :: Eq a => a -> [(a,b)] -> Maybe b
mylookup n [] = Nothing 
mylookup n ((x,y) : t) = if n == x then Just y 
                       else mylookup n t    



-- exercicio 36 

mypreCrescente :: Ord a => [a] -> [a] 
mypreCrescente [] = [] 
mypreCrescente (x:y:t) = if x <= y then x : mypreCrescente (y:t) 
                        else [x] 


-- exercicio 37  

iSort' :: Ord a => [a] -> [a] 
iSort' [] = [] 
iSort' (h:t) = insert' h (iSort' t)

insert' :: Ord a => a -> [a] -> [a] 
insert' n [] = [n] 
insert' n (h:t) = if n <= h then n : h : t 
               else h : insert' n t 



-- exercicio 38 

mymenor :: String -> String -> Bool 
mymenor [] []        = True 
mymenor [] l         = True 
mymenor l []         = False 
mymenor (x:xs) (h:t) | x > h     = False 
                     | x < h     = True 
                     | otherwise = mymenor xs t 



-- exercicio 39 

myelemMSet :: Eq a => a -> [(a,Int)] -> Bool 
myelemMSet n [] = False 
myelemMSet n ((x,y) : t) = if n == x then True 
                         else myelemMSet n t  


-- exercicio 40 

myconverteMSet :: [(a, Int)] -> [a] 
myconverteMSet [] = [] 
myconverteMSet ((x,y):t) = if y > 0 then x : myconverteMSet ((x,(y-1)):t) 
                         else  myconverteMSet t 



-- exercicio 41 

myinsereMSet :: Eq a => a -> [(a,Int)] -> [(a,Int)] 
myinsereMSet n [] = [(n,1)] 
myinsereMSet n ((x,y):t) = if n == x then ((x,(y+1)):t) 
                         else (x,y) : myinsereMSet n t 



-- exercicio 42 

myremoveMSet :: Eq a => a -> [(a,Int)] -> [(a,Int)] 
myremoveMSet n [] = [] 
myremoveMSet n ((x,y):t) | x == n && (y-1) > 0  = ((x,(y-1)):t)
                         | x == n && (y-1) == 0 = t 
                         | otherwise = (x,y) : myremoveMSet n t 




-- exercicio 43 

constroiMSet :: Ord a => [a] -> [(a,Int)] 
constroiMSet [] = [] 
constroiMSet (h1:h2:t) = auxx 1 (h1:h2:t) 


auxx :: Ord a => Int -> [a] -> [(a,Int)] 
auxx acc [x] = [(x,acc)] 
auxx acc (h1:h2:t) = if h1 == h2 then auxx (acc+1) (h2:t) 
                   else (h1,acc) : auxx 1 (h2:t) 


-- exercicio 44 

mypartitionEithers :: [Either a b] -> ([a],[b]) 
mypartitionEithers [] = ([],[])
mypartitionEithers (h:t) = case h of 
      Left a -> (a:x,y)
      Right b -> (x, b:y) 
    where (x,y) = mypartitionEithers t  



-- exercicio 45 

mycatMaybes :: [Maybe a] -> [a] 
mycatMaybes [] = [] 
mycatMaybes (h:t) = case h of 
       Just a -> a : mycatMaybes t 
       Nothing -> mycatMaybes t 



-- exercicio 46 

data Movimento = Norte | Sul | Este | Oeste 
               deriving Show 


caminho :: (Int,Int) -> (Int,Int) -> [Movimento] 
caminho (x,y) (x2,y2) | x > x2 = Oeste : caminho (x-1,y) (x2,y2) 
                      | x < x2 = Este : caminho (x+1,y) (x2,y2) 
                      | y > y2 = Sul : caminho (x,y-1) (x2,y2) 
                      | y < y2 = Norte : caminho (x,y+1) (x2,y2)
                      | otherwise = [] 


-- exercicio 47 

hasLoops :: (Int,Int) -> [Movimento] -> Bool 
hasLoops (x,y) [] = False 
hasLoops (x,y) (h:t) = case h of 
                    Norte -> aux90 (x,y) (x,y+1) t 
                    Sul -> aux90 (x,y) (x,y-1) t 
                    Este -> aux90 (x,y) (x+1,y) t 
                    Oeste -> aux90 (x,y) (x-1,y) t 
                    



aux90 :: (Int,Int) -> (Int,Int) -> [Movimento] -> Bool 
aux90 (xi,yi) (xa,ya) [] = if xi == xa && yi == ya then True 
                         else False 
aux90 (xi,yi) (xa,ya) (h:t) = if xi == xa && yi == ya then True 
                         else case h of 
                             Norte -> aux90 (xi,yi) (xa,ya+1) t 
                             Sul -> aux90 (xi,yi) (xa,ya-1) t 
                             Oeste -> aux90 (xi,yi) (xa,ya-1) t 
                             Este -> aux90 (xi,yi) (xa,ya+1) t 




-- exercicio 48

type Ponto = (Float,Float) 
data Rectangulo = Rect Ponto Ponto 

contaQuadrados :: [Rectangulo] -> Int 
contaQuadrados [] = 0 
contaQuadrados ((Rect (x1,y1) (x2,y2)) :t) = if abs (x1-x2) == abs (y1-y2) then 1 + contaQuadrados  t  
                                          else contaQuadrados t


-- exercicio 49

areaTotal :: [Rectangulo] -> Float 
areaTotal [] = 0 
areaTotal ((Rect (x1,y1)(x2,y2)):t) = abs (x1-x2) * abs (y1-y2) + areaTotal t



-- exercicio 50 

data Equipamento = Bom | Razoavel | Avariado 
                 deriving Show 


naoReparar :: [Equipamento] -> Int 
naoReparar [] = 0 
naoReparar (h:t) = case h of 
   Avariado -> naoReparar t 
   _        -> 1 + naoReparar t 