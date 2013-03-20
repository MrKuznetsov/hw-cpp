primeNums :: [Int]

primeNums = 2 : [ x | x <- [3..], isPrime x]

isPrime x = helper x (x - 1)
	where
		helper a b | b == 1 = True
				   | otherwise = if (mod a b) == 0
								 then False
								 else helper a (b - 1)
				   