getRomb :: Int -> String
getRomb n = getRombHlp (n - 1) (2 * (n - 1))

getRombHlp n (-1) = []
getRombHlp n l = (getLine (n - abs(n - l))) ++ (getRombHlp n (l - 1))
	where
		helper 0 0 = "\n"
		helper l 0 = '*' :  helper (l - 1) 0
		helper l m = ' ' : helper l (m - 1)
		
		getLine l = helper (1 + l * 2) (n - l)