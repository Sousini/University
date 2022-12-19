

-- Questão 1 

-- a 
 
any' :: (a -> Bool) -> [a] -> Bool  
any' _ [] = False 
any' p (h:t) = p h || any' p t  


-- b 

zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c] 
zipWith' 