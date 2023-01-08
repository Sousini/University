


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
zipWithBT f _ Empty = Empty 
zipWithBT f (Node x e d) (Node n e1 d1) = Node (f x n) (zipWithBT f e e1) (zipWithBT f d d1) 

-- h 

unzipBT :: BTree (a,b,c) -> (BTree a,BTree b,BTree c) 
unzipBT Empty = (Empty, Empty, Empty)
unzipBT (Node (a,b,c) e d) = (Node a e1 d1, Node b e2 d2, Node c e3 d3) 
                  where (e1,e2,e3) = unzipBT e 
                        (d1,d2,d3) = unzipBT d 


-- Questão 2 

-- a 

minimo :: Ord a => BTree a -> a 
minimo (Node x Empty Empty) = x 
minimo (Node x e d) =