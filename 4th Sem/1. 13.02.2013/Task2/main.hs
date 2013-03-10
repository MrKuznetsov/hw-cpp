fibonachi :: Integer -> Integer
fibonachi 0 = 0
fibonachi 1 = 1
fibonachi x = fibonachi (x - 1) + fibonachi (x - 2)