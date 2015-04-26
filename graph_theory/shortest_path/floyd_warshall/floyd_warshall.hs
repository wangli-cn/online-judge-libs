{-# LANGUAGE OverloadedStrings, MultiWayIf, ScopedTypeVariables #-}
import qualified Data.ByteString.Char8 as B
import Data.Maybe (fromJust)
import Control.Monad
import Control.Monad.Trans
import Control.Monad.Trans.Maybe
import Data.Array.IO


type Graph = IOArray (Int, Int) Int

inf :: Int
inf = 10000000

solve :: Int -> Graph -> IO Int
solve n g = do
  {-getElems g >>= \x -> print x-}
  forM_ [0 .. n-1] (\k -> 
    forM_ [0 .. n-1] (\i -> 
        forM_ [0 .. n-1] (\j -> do
            ij <- readArray g (i, j)
            ik <- readArray g (i, k)
            kj <- readArray g (k, j)
            when (ij > (ik + kj)) $ writeArray g (i, j) (ik + kj)
            return ()
          )
      )
   )
  {-getElems g >>= \x -> print x-}
  l <- forM [0 .. n-1] (\i -> do
      m <- readArray g (i, i)
      return m
    ) 

  if (minimum l) == inf
    then return (-1)
    else return $ minimum l


main = runMaybeT $ forever $ do
  s <- lift B.getLine
  let n = fst . fromJust $ B.readInt s
  when (n == 0) mzero
  graph <- lift $ newArray ((0, 0), (n-1, n-1)) inf
  lift $ forM_ [0..n-1] (\i -> do s <- B.getLine
                                  let l = zip [0..] $ map (fst . fromJust . B.readInt) $ B.words s
                                  mapM_ (\(j, e) -> when (e > 0) $ writeArray graph (i, j) e) l
                                  return ())
  sol <- lift $ solve n graph
  lift $ print sol
