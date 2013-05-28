import Data.Array(Array(..), array, bounds, elems, (//), (!))
import Data.List(foldl')
import Data.Char
import Control.Monad.State

type HashData = Int
type HashList = [(String, HashData)]

--SIZE 32
data Hash = Hash {
	 hfunc :: (String -> Int)
	,table :: Array Int HashList
}

find :: String -> Hash -> Maybe HashData
find s h = lookup s ((table h)!((hfunc h) s))

insert :: (String, HashData) -> Hash ->Hash
insert d h = Hash (hfunc h) (htab // [(ind, hlistnew)])
	where
		ind = ((hfunc h) (fst d))
		htab = table h
		hlist = htab ! ind
		hlistnew = if (lookup (fst d) hlist) == Nothing
				   then d:hlist
				   else hlist

withOut :: String -> HashList -> HashList
withOut _ [] = []
withOut s (x:xs) = if s == (fst x)
				   then withOut s xs
				   else x : withOut s xs
				   
delete :: String -> Hash -> Hash
delete s h = Hash (hfunc h) (htab // [(ind, hlistnew)])
	where
		ind = ((hfunc h) s)
		htab = table h
		hlistnew = withOut s (htab ! ind)

deleteList :: [String] -> Hash -> Hash
deleteList [] h = h
deleteList (x:xs) h = deleteList xs (delete x h)

insertList :: [(String, HashData)] -> Hash -> Hash
insertList [] h = h
insertList (x:xs) h = insertList xs (insert x h)

deleteSt :: [String] -> State (Hash) ()
deleteSt xs = modify $ flip deleteList xs

insertSt :: [(String, HashData)] -> State (Hash) ()
insertSt d = modify $ flip insertList d