In Go, a variadic function similar to diagnose function can be implemented with the help of `fmt.Printf` function and the built-in `error` interface. Here is the closest implementation we can make in Go:

go
package main

import (
    "fmt"
    "os"
)

func diagnose(errnum int, format string, a ...interface{}) {
    // we don't have direct representation of progress_len in go
    // if progress_len > 0 {
    //     fmt.Fprint(os.Stderr, "\n")
    //     progress_len = 0
    //}

    errMsg := fmt.Sprintf(format, a...)
    err := fmt.Errorf("%d: %s", errnum, errMsg)

    fmt.Fprintln(os.Stderr, err)
}


There are a few minor incompatibilities due to the differences between C and Go:

- There's no direct equivalent for a `progress_len` (`var progress_len int`) variable, as you'd typically use channels, select statements, contexts and/or standard error handling to abort or handle errors midway in Go. Also, the i/o system is different from in C.
  
- There's zero value for error object (`errnum`) in Go. Implementations typically use `nil`.
  
- Go have different way to throw an error where first you just formatted string with necessary info and then pass it into `fmt.Errorf` to create an error. Output to os.Stderr, we use `fmt.Fprintln`.