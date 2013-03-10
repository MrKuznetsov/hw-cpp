sumOfNum x | x < 10 = x
		   | otherwise =(x `mod` 10) + sumOfNum (x `div` 10)