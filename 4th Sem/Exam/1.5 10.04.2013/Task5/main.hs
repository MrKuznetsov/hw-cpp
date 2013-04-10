isCorrect :: String -> Bool
isCorrect (x:xs) = helper 0 (x:xs) 0
		where 
		 --   checkType s t = (t == 1 && s == ')') || (t == 2 && s == '}') || (t == 3 && s == ']')
			getType s   | s == '(' = 1
						| s == '{' = 2
						| s == '[' = 3
						| otherwise = 0
			
			checkT s t = (t == 1 && s == ')') || (t == 2 && s == '}') || (t == 3 && s == ']')
						  
			isOpen s = (s == '(') || (s == '{') || (s == '[')
			
			helper a [] t = a == 0
			helper a (y:ys) t | a < 0 = False
							  | otherwise = if isOpen y
										    then helper (a + 1) ys (getType y)
										    else if (checkT y t)
											then helper (a - 1) ys t
										    else False

