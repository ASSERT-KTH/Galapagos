Since Golang does not have global exception handling like C, we might have to pass the error along with function return, or panic into higher scopes, or use log package. Due to error handling mechanism in go, it is difficult to translate some of the statements directly. Here is a semantically similar approach as to preserve the behavior, but the use of `errno` and `exit failure` might not align perfectly with Go programming paradigm.

Go
import (
    "os"
    "fmt"
)

func writeError() {
    if err := recover(); err != nil {
        fmt.Fprintf(os.Stdout, "unhandled exception: %v", err)
        os.Exit(1)
    } 
}
 

This version runs the following action on a panic detection, prints detected error value to Stdout then exits with failure. However Go idiomatic way of error handling avoids use of panic-recovers and guided by... Fail early, return on first detection of 'non-nil' (and nil in some cases like http.get) errors.