Go does not directly support variable-length argument lists with different types (like `errnum` as an int and `fmt` as a string in your C function). Using the `...interface{}` to replace `...` in Go implies that the functions may receive an arbitrary count and types of parameters, such as `Diagnose(errnum int, a ...interface{})`. But if we follow your original function's signature strictly (`errnum` as an int and `fmt` as a string), we could use `fmt.Sprintf` to format the error message:

go
import (
    "fmt"
    "log"
    "os"
)

// global var recording the length progress;
// extern int progress_len;
var progressLen int

// determine what to put here.
// #define stderr 1 

func diagnose(errnum int, fmtStr string, a ...interface{}) {
    if progressLen > 0 {
        fmt.Fprint(os.Stderr, "\n")
        progressLen = 0
    }
    errMsg := fmt.Sprintf(fmtStr, a...)
    log.Print(fmt.Sprintf("Error %d: %s", errnum, errMsg))
}


In this code, `fmt.Sprintf` formats according to a format specifier, the same as `printf` in C but returns the resulting string, `format` is the required format string (specified in your C code as `char const *fmt`), `n` are the format values:

However, for more “cleanliness” and idianeous Go code, I may suggest taking `errnum` as `error`, not `int`:

go
import (
    "fmt"
    "os"
)

var progressLen int

func diagnose(errNum error, fmtStr string, a ...interface{}) {
    if progressLen > 0 {
        fmt.Fprint(os.Stderr, "\n")
        progressLen = 0
    }

    errMsg := fmt.Sprintf(fmtStr, a...)
    fmt.Fprintf(os.Stderr, "Error: %v: %s", errNum, errMsg)
}


Consider this possibility with your system/design necessities.