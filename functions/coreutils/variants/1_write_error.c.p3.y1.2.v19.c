Since Go language doesn't use errno directly and the error function completely acts differently in Go-language especially compared to C, here is the Go variant keeping semantics same by using the Errorf function from the fmt package and the os package for handling standard output

go
package main

import (
  "fmt"
  "os"
)

func writeError() {
  f := os.Stdout
  err := f.Sync()
  if(err != nil) {
    fmt.Printf("sync failed: %s", err)
    os.Exit(1)
  }
  err = f.Sync()
  errStr := err.Error()
 if(err!=nil){
  fmt.Errorf("write error %s, errStr") 
  os.Exit(1)
  }
}	


The os.Exit(1) simulates the call to exit(EXIT_FAILURE) in the C code