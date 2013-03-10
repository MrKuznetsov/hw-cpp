reverse' :: [a] -> [a]
reverse' = foldl (flip (:)) []