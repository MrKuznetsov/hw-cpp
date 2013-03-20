data Tree a = Nil
            | Branch a (Tree a) (Tree a)
			

zeroElems :: (Integral a) => (Tree a) -> [a]

zeroElems Nil = []
zeroElems (Branch x a b) = x : ((zeroElems a) ++ (zeroElems b)) 