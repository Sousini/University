

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