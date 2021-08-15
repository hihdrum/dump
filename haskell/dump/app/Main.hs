module Main where

import System.IO
import Control.Monad.Extra
import qualified Data.ByteString as B
import Text.Printf

import Lib

readByte :: IO B.ByteString
readByte = B.hGet stdin 1

printByte :: PrintfType t => B.ByteString -> t
printByte x = printf "%02x " $ Prelude.head $ B.unpack x

procReadByte :: (B.ByteString -> IO a) -> IO Bool
procReadByte f = do byte <- readByte
                    if B.null byte
                    then return False
                    else do f byte
                            return True

main :: IO ()
main = whileM $ procReadByte printByte
