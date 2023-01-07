{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{-# HLINT ignore "Redundant if" #-}
import Control.Applicative (Applicative(liftA2))
import Data.Time.Format.ISO8601 (recurringIntervalFormat)



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

-- Questão 2 

type ConjInt = [Intervalo] 
type Intervalo = (Int,Int) 


-- a 

elems :: ConjInt -> [Int] 
elems [] = [] 
elems ((a,b):t) | a == b = a : elems t 
                | a < b = a : elems ((a+1,b) :t) 


-- b ????????

geraconj :: [Int] -> ConjInt 
geraconj [] = [] 
geraconj l = let a = groupBy (\ x y -> x == y-1) l 
                 b = map convInt a 
             in b 

convInt :: [Int] -> Intervalo 
convInt l = (head l, last l) 

groupBy :: (a -> a -> Bool) -> [a] -> [[a]] 
groupBy _ []       = [] 
groupBy eq (x:xs) = (x:ys) : groupBy eq zs 
   where (ys,zs) = span (eq x) xs



-- Questão 3 

data Contacto = Casa Integer 
              | Trab Integer 
              | Tlm Integer 
              | Email String 
    deriving (Show) 

type Nome = String 
type Agenda = [(Nome, [Contacto])] 


--  a 

acrescEmail :: Nome -> String -> Agenda -> Agenda 
acrescEmail nome email [] = [(nome, [Email email])]
acrescEmail nome email agenda = agenda ++ [(nome, [Email email])]
