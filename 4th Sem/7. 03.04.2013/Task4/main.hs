import Control.Monad.Cont

helpMap :: (a -> b) -> [a] -> Cont [b] [b]
helpMap _ [] = return []
helpMap f (x:xs) = helpMap f xs >>= return . (f x :)
cpsMap f xs = runCont (helpMap f xs) id

helpFilter :: (a -> Bool) -> [a] -> Cont [a] [a]
helpFilter _ [] = return []
helpFilter f (x:xs) = helpFilter f xs >>= return . (filter f [x]!!0 :)
cpsFilter f xs = runCont (helpFilter f xs) id