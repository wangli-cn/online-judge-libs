import Prelude hiding (sqrt)

sqrt n = go n 1.0 10000
  where 
    go n t1 0 = t1
    go n t1 iter = go n (0.5 * (t1 + n / t1)) (iter-1)

main = do
  l <- getLine
  let n = (read l) :: Double
  let ans = sqrt n
  print $ ans
