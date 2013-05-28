module Main 
	where 
		import System.IO
		type Number = String
		type Name = String
		type Phone = [(Name, Number)]
		
		findByName :: Name -> Phone -> Number
		findByName a [] = "There is no phone with that name"
		findByName a (x:xs) = if a == (fst x)
							  then snd x
							  else findByName a xs
							  		
		findByNumber :: Number -> Phone -> Name
		findByNumber a [] = "There is no phone with that number"
		findByNumber a (x:xs) = if a == (snd x)
							    then fst x
							    else findByNumber a xs
		getAndOpenFile :: IOMode -> IO Handle
		getAndOpenFile mode = do 
			name <- getLine
			catch (openFile name mode) (\ err -> do 
													putStrLn("Error openning file" ++ show err ++ "\n") 
													getAndOpenFile mode)
		writePhoneBook [] _ = do 
			putStrLn "Writeing is done"
		writePhoneBook (x:xs) tHandle = do
			hPutStrLn tHandle (fst x)
			hPutStrLn tHandle (snd x)
			writePhoneBook xs tHandle	
		readPhoneBook  tHandle xs = do 
			p <- hIsEOF tHandle
			if p 
			then do 
				putStrLn "File is readed"
				return xs
			else do
				name <- hGetLine tHandle
				num <- hGetLine tHandle
				phone <- readPhoneBook tHandle ((name, num):xs)
				return phone	
		main = do
			hSetBuffering stdin LineBuffering
			doLoop []
		doLoop xs = do
			putStrLn "Enter command"
			command <- getLine
			case command of
			 '0': _ -> return()
			 '1': _ -> do 
					putStrLn "Reading phone number, input Name then Number"
					name <- getLine
					num <- getLine
					doLoop ((name, num) : xs)
			 '2': _ -> do
					putStrLn "Find by name, enter name"
					name <- getLine
					putStrLn (findByName name xs)
					doLoop xs
			 '3': _ -> do
					putStrLn "Find by number, enter number"
					name <- getLine
					putStrLn (findByNumber name xs)
					doLoop xs			
			 '4': _ -> do
					putStrLn "Save to"
					toHandle  <- getAndOpenFile WriteMode 
					writePhoneBook xs toHandle
					doLoop xs		
			 '5': _ -> do
					putStrLn "Read from"
					toHandle  <- getAndOpenFile ReadMode 
					phone <- readPhoneBook toHandle []
					doLoop phone						
			 '6': _ -> do 
					putStrLn $ show xs
					doLoop xs
			
