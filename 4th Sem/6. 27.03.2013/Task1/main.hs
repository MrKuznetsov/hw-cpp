data Tree a = EmptyTree
           | Node a (Tree a) (Tree a)
		   
writeTree :: Tree Char -> String
writeTree EmptyTree = "e"
writeTree (Node x l r) = 'n' : x : ((writeTree l) ++ (writeTree r))
		   
readTree :: String -> Tree Char
readTree xs = fst (read' xs)
	where read' ('e':xs) = (EmptyTree, xs)
	      read' ('n':x:xs) = let (l, s) = read' xs in
								let(r, s2) = read' s in
									(Node x l r, s2)