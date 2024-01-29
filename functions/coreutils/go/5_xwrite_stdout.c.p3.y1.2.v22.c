package main

import (
    "os"
    "log"
)

func xwrite_stdout(buffer []byte, n_bytes int) {
    if n_bytes > 0 {
         numBytes, err := os.Stdout.Write(buffer[:n_bytes])
         if err != nil || numBytes < n_bytes {
             log.Fatalf("error writing %s", "standard output");
        }
    }
}