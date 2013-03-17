import Data.List (elemIndex)
import Data.Maybe (fromJust)

maxSum :: (Integral a) => [a] -> Int
maxSum (x:xs) = fromJust (elemIndex (maximum list) list) 
		   where list = zipWith (+) (x:xs) xs