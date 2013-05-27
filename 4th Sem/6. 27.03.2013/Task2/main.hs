type Polinom = [Int]

increase :: Polinom -> Int -> Polinom
increase p len = if len <= 0
				 then p
				 else p ++ [0 | x <-[0..(len - 1)]]
preIncrese p len = [0 | x <-[0..(len - 1)]] ++ p			 
				 
add :: Polinom -> Polinom -> Polinom
add a b = zipWith (+) (increase a (length b - length a)) (increase b (length a - length b))

mul :: Polinom -> Polinom -> Polinom
mul a b = helper a b 0
	where 
		helper a [] _ = []
		helper a (x:xs) c =  add ((preIncrese [] c) ++ [ x * y | y <- a]) (helper a xs (c+1))
		
showPolinom :: Polinom -> String
showPolinom xs = helper xs 0
	where 
		helper [] _ = ""
		helper (0:ys) a = helper ys (a+1)
		helper (y:ys) 0 = show y ++ "+" ++ helper ys (1)
		helper (y:[]) a = show y ++ "x^" ++ show a
		helper (y:ys) a = show y ++ "x^" ++ show a ++ "+" ++ helper ys (a+1)