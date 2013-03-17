evenNum1 :: (Integral a) => [a] -> a
evenNum1 xs = sum (map (\y -> 1 - ( mod y 2)) xs)

evenNum2 :: (Integral a) => [a] -> a
evenNum2 xs =  length (filter (even) xs)

evenNum3 :: (Integral a) => [a] -> a
evenNum3 xs = foldr (\ x y -> y + 1 - (mod x 2)) 0 xs