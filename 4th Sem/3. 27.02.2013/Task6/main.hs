isCorrect :: String -> Bool
isCorrect (x:xs) = helper 0 (x:xs)
		where 
			helper a [] = a == 0
			helper a (y:ys) | a < 0 = False
							| otherwise = if y == '('
										  then helper (a + 1) ys
										  else if y == ')'
										  then helper (a - 1) ys
										  else helper a ys

