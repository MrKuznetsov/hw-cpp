module Main 
	where 
		import System.IO
		
		addToSorted :: Int -> [Int] -> [Int]
		addToSorted  a xs = helper a [] xs
			where 
				helper a ys [] = ys ++ [a]
				helper a ys (z:zs) = if a <= z
									 then ys ++ (a:z:zs)
									 else helper a (ys ++ [z]) zs
		main = do
			hSetBuffering stdin LineBuffering
			doLoop []
		doLoop xs = do
			putStrLn "Enter command"
			command <- getLine
			case command of
			 '0': _ -> return()
			 '1': _ -> do 
					putStrLn "Reading number "
					num <- getLine
					doLoop (addToSorted (read num :: Int) xs)
			 '2': _ -> do
					putStrLn "Reading number "
					num <- getLine
					doLoop (filter (/= (read num :: Int)) xs)
			 '3': _ -> do 
					putStrLn $ show xs
					doLoop xs
			
