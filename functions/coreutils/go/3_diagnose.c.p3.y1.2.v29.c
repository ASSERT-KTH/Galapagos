In Go, a semantically similar solution is not available due to a variety of differences between how the two languages, C and Go, function. Here is the closest version which can be built in Go:

go
import (
    "fmt"
    "os"
)

var progressLen int // Define this wherever you think is necessary 

func diagnose(errnum error, fmtString string, a ...interface{}) {
    if progressLen > 0 {
        fmt.Fprintln(os.Stderr)
        progressLen = 0
    }
        
    fmt.Fprintln(os.Stderr, fmt.Sprintf(fmtString, a...))
    if errnum != nil {
        fmt.Fprint(os.Stderr, errnum.Error())
    }
}


Key changes:

1. Go doesn't support variable-length argument functions as C does, but `...interface{}` is the closest.
2. The feature of redirecting output to `stderr` can be easily implemented using Go's `fmt.Fprintln` function.
3. Go doesn't have a variable argument list macro `va_start`, `va_end`, and equivalent as C, but the `fmt` package function `Sprintf` can serve similar functionality.

*Note: The error number argument errnum has the type error rather than integer unlike in the C version. This is because error handling in Go is usually done with error types rather than error codes, which means it can include complex error structures rather just a single int error number.*
