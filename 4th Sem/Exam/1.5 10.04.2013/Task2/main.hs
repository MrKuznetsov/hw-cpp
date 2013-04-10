getCornMatrix :: Int -> [[Int]]
getCornMatrix n = getLineMatrix n n

getLineMatrix n 0 = []
getLineMatrix n a = (helper n a) : getLineMatrix n (a - 1)
	where
		helper 0 a = []
		helper m a = if m > a
					 then (n - a + 1) : helper (m - 1) a
					 else (a - m + 1 + n - a) : helper (m - 1) a