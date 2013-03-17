data Tree a = Nil
            | Branch (Tree a) (Tree a)
					
minLength :: (Tree a) -> Int
minLength Nil = 0
minLength (Branch l r) = 1 + min (minLength l) (minLength r)