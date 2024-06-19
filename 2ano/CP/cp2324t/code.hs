import Cp
import List
import ListUtils
import BTree
import Nat






oracle :: [Integer]

oracle = [
    1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845,
    35357670, 129644790, 477638700, 1767263190, 6564120420, 24466267020,
    91482563640, 343059613650, 1289904147324, 4861946401452 ]

cat ::  Int -> (Integer, Integer)
cat = prj . for loop inic where
    loop (a,b) = (b, a*2)
    inic = (1,1)
    prj = id


-- Função principal para calcular o n-ésimo número de Catalan usando recursão simples
f :: Integer -> Integer
f 0 = 1
f n = g n

-- Função g auxiliar para calcular o número de Catalan usando recursão
g :: Integer -> Integer
g 0 = 1
g m = sum [f k * f (m - 1 - k) | k <- [0..(m - 1)]]