


-- Questão 1 

data BTree a = Empty 
             | Node a (BTree a) (BTree a) 
          deriving Show 


-- a 

altura :: BTree a -> Int 
altura Empty = 0
altura (Node _ e d) = 1 + max (altura e) (altura d) 

-- b 

contaNodos :: BTree a -> Int 
contaNodos Empty = 0 
contaNodos (Node _ e d) = 1 + contaNodos e + contaNodos d 

-- c 

folhas :: BTree a -> Int 
folhas Empty = 0 
folhas (Node _ Empty Empty) = 1 
folhas (Node _ e d) = folhas e + folhas d 


-- d 

prune :: Int -> BTree a -> BTree a 
prune n Empty = Empty 
prune 0 _ = Empty 
prune n (Node x e d) = Node x (prune (n-1) e) (prune (n-1) d) 


-- e 

path :: [Bool] -> BTree a -> [a] 
path _ Empty = [] 
path [] _ = [] 
path (h:t) (Node x e d) = if not h then x : path t e 
                        else x : path t d  


-- f

mirror :: BTree a -> BTree a 
mirror Empty = Empty 
mirror (Node x e d) = Node x (mirror d) (mirror e) 

-- g 

zipWithBT :: (a -> b -> c) -> BTree a -> BTree b -> BTree c 
zipWithBT f Empty _ = Empty 
zip