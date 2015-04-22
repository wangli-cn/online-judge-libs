{-# LANGUAGE OverloadedStrings #-}
import qualified Data.ByteString.Char8 as B
import Control.Monad
import Control.Monad.Trans
import Control.Monad.Trans.State.Strict
import Data.Maybe (fromJust)
import Data.Array.IO

inf :: Int
inf = 10000000

forward :: Int -> IOArray Int Int -> IOArray Int Int -> StateT [Int] IO ()
forward n pos prev_small = do
  forM_ [1 .. n] (\i -> do 
      stack <- get
      x <- lift $ readArray pos i
      let new_stack = dropWhile (>= x) stack
      if null new_stack
        then lift $ writeArray prev_small i (-1)
        else lift $ writeArray prev_small i (head new_stack)
      put (x:new_stack)
    ) 


backward :: Int -> IOArray Int Int -> IOArray Int Int -> StateT [Int] IO ()
backward n pos next_small = do
  let sl = reverse [1 .. n]
  forM_ sl (\i -> do 
      stack <- get
      x <- lift $ readArray pos i
      let new_stack = dropWhile (>= x) stack
      if null new_stack
        then lift $ writeArray next_small i (-1)
        else lift $ writeArray next_small i (head new_stack)
      put (x:new_stack)
    ) 


solve :: Int -> IOArray Int Int -> IOArray Int Int -> IO [Int]
solve n arr pos = do
  prev_small <- newArray (1, n) inf
  next_small <- newArray (1, n) inf
  runStateT (forward n pos prev_small) []
  runStateT (backward n pos next_small) []

  res <- forM [1..n] (\i -> do
                              a <- readArray prev_small i
                              b <- readArray next_small i
                              let larger = maximum [a, b]
                              p <- if larger == -1 then (return 0) else readArray arr larger 
                              return p)
  return res


main = do
  l <- B.getContents >>= (\s -> return $ B.words s)
  let n = fst . fromJust $ B.readInt (head l)
  let rest = drop 1 l
  arr <- newArray (1, n) inf
  pos <- newArray (1, n) inf
  let l = map (fst . fromJust . B.readInt) $ rest
  mapM_ (\(i, e) -> writeArray arr i e) $ zip [1..] l
  mapM_ (\(i, e) -> writeArray pos e i) $ zip [1..] l
  sol <- solve n arr pos
  mapM_ (putStrLn . show) sol
