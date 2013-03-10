--getListPos :: [a] -> a -> Integer
--getListPos x:xs b | x == b = 0
--				  | otherwise = 1 + (getListPos xs b)

getListPos :: Integer -> [Integer] -> Integer
getListPos a x | (head x) == a = 0
			   | otherwise = 1 + (getListPos a (tail x))