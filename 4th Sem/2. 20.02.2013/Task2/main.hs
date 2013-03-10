pwOfTwo :: Integer -> [Integer]
pwOfTwo n = [ 2 ^ x | x <- [1..n] ]