{-# LANGUAGE BangPatterns #-}

import Control.Monad (when)

genParen :: Int -> Int -> String -> IO ()
genParen !open_stock !close_stock s = do
  if (open_stock == 0 && close_stock == 0) 
    then do
      putStrLn s
      return ()
  else do 
    when (open_stock > 0) $ genParen (open_stock-1) (close_stock+1) (s ++ "(")
    when (close_stock > 0) $ genParen (open_stock) (close_stock-1) (s ++ ")")


main :: IO ()
main = do
  genParen 10 0 ""
