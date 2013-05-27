import Data.List

pHelp :: Int -> [[Int]]
pHelp 0 = [[]]
pHelp n = [1..n] >>= (\x -> map (x:) (pHelp (n - x)))

partitions :: Int -> [[Int]]
partitions x = nub ( map sort (pHelp x))

