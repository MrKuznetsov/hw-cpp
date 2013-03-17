isDiffrent :: (Eq a) => [a] -> Bool

isDiffrent xs = helper [] xs
		where 
			  helper _ [] = True
			  helper (ys) (z:zs) = if elem z ys
								   then False
								   else helper (z:ys) zs