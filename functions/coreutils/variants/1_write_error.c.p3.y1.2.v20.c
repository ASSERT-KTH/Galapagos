Since Go does not directly support the concepts of errno or the exact sequence of steps as presented in the C code, an exactly equivalent function can't be created in Go. But the following function can effectively demonstrate a similar kind of error handling mechanism in Go for some arbitrary error condition. 

go
import (
    "os"
    "fmt"
)

func writeError() {
    // error creation (in Go usually errors are returned by functions, here's a simulation)
    err := fmt.Errorf("write error")

    // typically instead of relying on external 'errno'-like entities in C 
    // Go usually returns the error value explicitly where multi-value like functions are used

    if err != nil { 
        fmt.Fprintln(os.Stderr, err) // write error to the standard error file descriptor
        os.Exit(1) // akin to exit failure in C
    }
}

Note that this snippet doesn't exactly translate the behavior of the original C function and practically much Go errors doesn't directly involve interactions with stdout. The original implementation thus might not usually be applicable in Go context except for some edge cases.