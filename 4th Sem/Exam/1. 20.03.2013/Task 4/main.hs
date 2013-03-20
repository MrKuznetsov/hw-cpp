sumCos (xs) = sumList / mulCos
	where (sumList, mulCos) = sumCos' xs 0 1
sumCos' [] s m = (s , m)
sumCos' (x:xs) s m =  sumCos' xs (x + s) ((cos x) * m)