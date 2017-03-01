import Control.Monad
import Data.Functor
import Text.Printf

comp a b = if(max a \= max b) max a > max b else b < a

qSort []     = []
qSort (x:xs) = qSort (filter (comp x) xs) ++ [x] ++ qSort (filter (not . comp x) xs)

main = do
    as <- words <$> getLine :: IO [String]
    forM (qSort as) (\x -> printf "%d " x)
