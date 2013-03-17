data Tree a = Nil
            | Branch (Tree a) (Tree a)
			
lengthTree :: (Tree a) -> Int
lengthTree Nil = 0
lengthTree (Branch l r) = 1 + max (lengthTree l) (lengthTree r)