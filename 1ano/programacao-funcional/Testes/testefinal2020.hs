{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{-# HLINT ignore "Redundant if" #-}
import Control.Applicative (Applicative(liftA2))



-- Questão 1 

-- a 

intersect' :: Eq a => [a] -> [a] -> [a] 
intersect' _ [] = [] 
intersect' [] _ = [] 
intersect' (h:t) l = if ocorre h l then h : intersect' t l 
                   else intersect' t l  


ocorre :: Eq a => a -> [a] -> Bool 
ocorre _ [] = False 
ocorre n (h:t) = if n == h then True 
               else ocorre n t  


-- b 

tails' :: [a] -> [[a]] 
tails' [] = [[]] 
tails' (h:t) = (h:t) : tails' t  

