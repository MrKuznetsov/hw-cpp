listOfLength :: Int -> [[Int]]
listOfLength 1 = [[1],[2],[3]]
listOfLength n = [1, 2, 3] >>= (\x -> map (x:) (listOfLength (n - 1)))