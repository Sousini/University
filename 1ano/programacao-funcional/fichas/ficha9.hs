module Ficha09 where

import System.Random
import Data.Char
import Data.List
import Data.Maybe
import qualified Data.Text as Text
import Control.Monad






-- Questão 1 

-- a 

bingo :: IO () 
bingo = do nl <- acumularNumeros [] 
           print nl  



acumularNumeros :: [Int] -> IO [Int] 
acumularNumeros l | length l == 90 = do return l 
                  | otherwise = do v <- randomRIO (1,90) 
                                   print v 
                                   getChar 
                                   let nl = if v `elem` l then l 
                                            else v:l in acumularNumeros nl 




-- b 

mastermind :: IO () 
mastermind = do (n1,n2,n3,n4) <- getKey 
                doGuess (n1,n2,n3,n4) 
                return () 



getKey :: IO (Int,Int,Int,Int) 
getKey = do a <- randomRIO (0,9) 
            b <- randomRIO (0,9) 
            c <- randomRIO (0,9) 
            d <- randomRIO (0,9) 
            return (a,b,c,d) 


getGuess :: IO (Int,Int,Int,Int) 
getGuess = do x <- getLine 
              if length x /= 4 || not $ all isDigit x 
              then getGuess 
              else return (let (a:b:c:d:resto) = x in (read [a], read [b], read [c], read [d])) 


doGuess :: (Int,Int,Int,Int) -> IO ()
doGuess (n1,n2,n3,n4) = do
    let listaNums = [n1,n2,n3,n4]
    (g1,g2,g3,g4) <- getGuess
    let numsC = 0 + (if n1 == g1 then 1 else 0) + (if n2 == g2 then 1 else 0) + (if n3 == g3 then 1 else 0) + (if n4 == g4 then 1 else 0)
    let numsS = 0 + (if n1 /= g1 && g1 `elem` (listaNums \\ [g2,g3,g4]) then 1 else 0) + 
                    (if n2 /= g2 && g2 `elem` (listaNums \\ [g3,g4]) then 1 else 0) + 
                    (if n3 /= g3 && g3 `elem` (listaNums \\ [g4]) then 1 else 0) + 
                    (if n4 /= g4 && g4 `elem` (listaNums \\ []) then 1 else 0)
    if numsC == 4 then print "Ganhaste, parabens!" else print $ "Valores corretos: " ++ show numsC ++ "   Valores no sitio errado: " ++ show numsS
    if numsC == 4 then return () else doGuess (n1,n2,n3,n4) 



-- Questão 2 

data Aposta = Ap [Int] (Int,Int) 


-- a 

valida :: Aposta -> Bool 
valida (Ap (n1:n2:n3:n4:n5:[]) (e1,e2)) =  and [x `elem` [1..50] | x <- [n1,n2,n3,n4,n5]] && all (\x -> `elem` [1..12]) [e1,e2] 
valida _ = False  


-- b 

comuns :: Aposta -> Aposta -> (Int,Int) 
comuns (Ap a1@(a:b:c:d:e:[]) (f,g)) (Ap a2@(h:i:j:k:l:[]) (m,n)) = (contaNums,contaEstr)
    where contaNums = length [x | x <- a1, x `elem` a2]
          contaEstr = length [y | y <- [f,g], y `elem` [m,n]]  


-- c  


-- (i)
instance Eq Aposta where
    (==) a b = comuns a b == (5,2)  
