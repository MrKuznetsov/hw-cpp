import Data.List (elemIndex)

firstPos :: (Eq a) => a -> [a] -> Maybe Int
firstPos a xs =  elemIndex a xs