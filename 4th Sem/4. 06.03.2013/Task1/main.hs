data Tree a = Nil
            | Branch a (Tree a) (Tree a)
			
findTree :: (a -> Bool) -> (Tree a) -> Bool

findTree f Nil = False
findTree f (Branch v l r) = if f v 
						  then True
						  else (findTree f l) || (findTree f r)