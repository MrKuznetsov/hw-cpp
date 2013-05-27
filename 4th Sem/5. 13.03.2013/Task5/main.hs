find :: [Int] -> Maybe Int
find [x] = Nothing
find (x:y:[]) = Nothing
find (x:y:z:[]) = if (y > x) && (y > z)
					then Just y
					else Nothing
find (x:y:z:xs) = if (y > x) && (y > z)
					then Just y
					else find (y:z:xs)