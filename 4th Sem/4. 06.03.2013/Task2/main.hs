data Tree a = Nil
            | Branch a (Tree a) (Tree a)
	
foldt :: (a -> a -> a) -> a -> (Tree a) -> a	
foldt _ z Nil = z
foldt f z (Branch v l r) = foldt f (f v (foldt f z l)) r 