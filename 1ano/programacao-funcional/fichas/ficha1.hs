import Data.Char
import Data.List


-- Exercicio 1 

-- a 

perimetro :: Float -> Float 
perimetro x = 2*pi*x  


-- b 

dist' :: (Double, Double) -> (Double, Double) -> Double 
dist' (x,y) (xs,ys) = sqrt ((x-xs)^2 + (y-ys)^2) 


-- c 

primUlt :: [a] -> (a,a) 
primUlt l = (head l, last l) 


-- d 

multiplo :: Int -> Int -> Bool 
multiplo m n = mod m n == 0   


-- e 

truncaImpar :: [a] -> [a] 
truncaImpar [] = [] 
truncaImpar l = if mod (length l) 2 == 0 then l 
                else tail l   


-- f 

max2 :: Int -> Int -> Int 
max2 n m = if n > m then n 
         else m  



-- g 

max3 :: Int -> Int -> Int -> Int 
max3 x y z = max2 (max2 x y) z  




-- Exercicio 2 

-- a 
nRaizes :: Float -> Float -> Float -> Int 
nRaizes x y z | delta1 < 0 = 0 
              | delta1 == 0 = 1 
              | delta1 > 0 = 2 
              where delta1 = (y^2) - 4*x*z  


-- b 
raizes :: Float -> Float -> Float -> [Float] 
raizes x y z |delta2 < 0 = []
             | delta2 == 0 = [r]
             | delta2 > 0 = [r1,r2]
             where
                delta2 = (y^2-4*x*z) 
                r= (-y)/(2*x)
                r1= ((-y)+sqrt delta2)/(2*x)
                r2= ((-y)-sqrt delta2)/(2*x)



-- Exercicio 3

type Hora = (Int,Int)
meiaNoiteEUmQuarto :: Hora
meiaNoiteEUmQuarto = (0,15)
duasMenosUmQuarto :: Hora 
duasMenosUmQuarto =(13,45)

-- alinea a

horaValida :: Hora -> Bool 
horaValida (h,m) = h>=0 && h<24 && m>=0 && m<60 

-- alinea b 

-- da verdade se a 1a e depois da 2a 
comparaHora :: Hora -> Hora -> Bool 
comparaHora (h1,m1) (h2,m2) = h1>h2 || h1 == h2 && m1>m2 
comparaHora' (h1,m1) (h2,m2) |h1>h2 = True
                             |h1 == h2 = m1>m2 
                             |h1<h2 = False 


-- alinea c 

horaParaMinutos :: Hora -> Int 
horaParaMinutos (h,m) = h*60 + m 



-- alinea d 

minutosParaHora :: Int -> Hora 
minutosParaHora m = (div m 60 ,mod m 60) 

-- alinea e 

diferencaHoras :: Hora -> Hora -> Int 
diferencaHoras h1 h2 = abs (horaParaMinutos h1)-(horaParaMinutos h2)  


-- alinea f 

adicionaMinutos :: Int -> Hora -> Hora 
adicionaMinutos m h = minutosParaHora (m + horaParaMinutos h)




-- Exercício 4 






-- Exercicio 5 

data Semaforo = Verde 
              | Amarelo 
              | Vermelho 
              deriving (Show, Eq)

-- alinea a

next :: Semaforo -> Semaforo 
next    Verde    =  Amarelo 
next    Amarelo  =  Vermelho 
next    Vermelho =  Verde 

-- alinea b 

stop :: Semaforo -> Bool 
stop    Vermelho = True 
stop    Verde    = False 
stop    Amarelo  = False 

-- alinea c 

safe :: Semaforo -> Semaforo -> Bool 
safe    _ Vermelho = True 
safe    Vermelho _ = True 
safe    _ _        = False 


-- Exercício 6 

data Ponto = Cartesiano Double Double | Polar Double Double
             deriving (Show,Eq)


-- a 

posx :: Ponto -> Double 
posx (Cartesiano x1 y1) = x1 
posx (Polar d a) =  d * (cos a) 


-- b 

posy :: Ponto -> Double 
posy (Cartesiano x1 y1) = y1 
posy (Polar d a) = d + (sin a)  


-- c 

raio :: Ponto -> Double 
raio (Cartesiano x1  y1) =  
raio (Polar d a) = d 





-- Exercicio 7

data Ponto = Cartesiano Double Double 
           | Polar Double Double 
           deriving (Show,Eq)

data Figura = Circulo Ponto Double 
            | Rectangulo Ponto Ponto 
            | Triangulo Ponto Ponto Ponto
            deriving (Show, Eq) 

circ :: Figura 
circ = Circulo (Cartesiano 0 0)2.3 

rect :: Figura 
rect = Rectangulo (Cartesiano 0 0) (Cartesiano 2 2)

-- alinea a 

poligono :: Figura -> Bool 
poligono (Circulo p r) = False 
poligono _             = True 

-- alinea b

vertices :: Figura -> [Ponto]
vertices (Circulo p r) = []
vertices (Triangulo v1 v2 v3) = [v1, v2, v3]
vertices (Rectangulo (Cartesiano a b)(Cartesiano x y)) =
                     [Cartesiano a b 
                     , Cartesiano a y 
                     , Cartesiano x y
                     , Cartesiano x b
                     ]

-- alinea c

dist :: Ponto -> Ponto -> Double 
dist (Cartesiano x1 x2) (Cartesiano y1 y2)
        = sqrt ((x2-x1)^2 + (y2-y1)^2) 

area :: Figura -> Double
area (Triangulo p1 p2 p3) =
     let a = dist p1 p2
         b = dist p2 p3
         c = dist p3 p1
         s = (a+b+c) / 2 -- semi-perimetro
     in sqrt (s*(s-a)*(s-b)*(s-c)) -- formula de Heron 

area (Circulo p r) = pi*r^2 

area (Rectangulo (Cartesiano a b)(Cartesiano x y)) = 
     let v1 = Cartesiano a b 
         v2 = Cartesiano a y
         v3 = Cartesiano x y 
         altura = dist v1 v2 
         largura = dist v2 v3
     in altura * largura  




