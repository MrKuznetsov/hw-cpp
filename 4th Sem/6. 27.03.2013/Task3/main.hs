data Tree a = EmptyTree
            | Node a (Tree a) (Tree a)
			deriving (Eq)
			
add :: (Ord a) => a -> Tree a -> Tree a
add x EmptyTree = Node x EmptyTree EmptyTree
add x (Node a l r) | x < a = Node a (add x l) r
				   | x > a = Node a l (add x r)
				   | otherwise = (Node a l r)
				   
find :: (Ord a) => a -> Tree a -> Bool
find _ EmptyTree = False
find x (Node a l r)| x < a = find x l
				   | x > a = find x r
				   | otherwise = True

height :: Tree a -> Int
height EmptyTree = 0
height (Node _ l r) = 1 + max (height l) (height r)				   

size :: Tree a -> Int
size EmptyTree = 0
size (Node _ l r) = 1 + (size l) + (size r)

remove :: (Ord a) => a -> Tree a -> Tree a
remove _ EmptyTree = EmptyTree
remove x (Node a l r) | x < a = Node a (remove x l) r
                      | x > a = Node a l (remove x r)
                      | otherwise = delete
    where delete | r == EmptyTree = l
                 | otherwise = Node (min r) l (remove(min r) r)
              where min (Node n l r) = if l == EmptyTree
                                       then n
                                       else min l