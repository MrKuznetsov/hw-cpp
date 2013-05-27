check :: (a -> Bool) -> [a] -> Bool
check p xs = null [ x | x <- xs, not (p x) ]