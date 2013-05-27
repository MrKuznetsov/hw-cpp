data Expr = Var
          | Const Int
          | Add Expr Expr
          | Mull Expr Expr
		  | Pow Expr Int
derivative :: Expr -> Expr	  
derivative (Const _) = (Const 0)
derivative Var = (Const 1)
derivative (Add a b) = Add(derivative a)(derivative b)
derivative (Mull a b) = Add (Mull (derivative a) b) (Mull a (derivative b))
derivative (Pow a 0) = Const 0
derivative (Pow a 1) = Const 1
derivative (Pow a b) = Mull (Const b) (Pow a (b - 1))

reduce (Add (Const a) (Const b)) =  (Const (a + b))
reduce (Add (Const 0) b) =  reduce b
reduce (Add a (Const 0)) = reduce a
reduce (Add a b) = Add (reduce a) (reduce b)
reduce (Mull (Const a) (Const b)) =  (Const (a * b))
reduce (Mull (Const 0) b) = (Const 0)
reduce (Mull a (Const 0)) = (Const 0)
reduce (Mull (Const 1) b) = reduce b
reduce (Mull a (Const 1)) = reduce a
reduce (Mull a b) = Mull (reduce a) (reduce b)
reduce (Pow a b) = Pow (reduce a) b


showExpr :: Expr -> String
showExpr (Const a) = show a
showExpr (Var) = "X"
showExpr (Add a b) = "(" ++ (showExpr a) ++ "+" ++ (showExpr b) ++ ")"
showExpr (Mull a b) = (showExpr a) ++ "*" ++ (showExpr b)
showExpr (Pow a b) = (showExpr a) ++ "^" ++ (show b)

showDiv :: Expr -> String
showDiv a = (showExpr (reduce a)) ++ "->"  ++ (showExpr $ reduce(derivative a))

