In Go, function equivalency to the provided C code cannot entirely be achieved due to deterministic differences between C and Go. However, the most semantically close version that maintains the original function's input is below:

Go
import (
        "fmt"
        "log"
    	"os"
)

var progressLen int

func diagnose(errNum int, fmt string, a ...interface{}) {
    if progressLen > 0 {
        fmt.Fprint(os.Stderr, "\n")
        progressLen = 0
    }
    verror(0, errNum, fmt, a...)
}

func verror(priority, errNum int, fmt string, a ...interface{}) {
    errorMsg := fmt.Sprintf(fmt, a...)
    if errNum != 0 {
        log.Printf("%s: %s\n", errorMsg, os.strerror(errNum))
    } else {
        log.Println(errorMsg)
    }
}


Explanation:
1. Go programming language does not contain a standard analogue to the variadic arguments (`va_list`, `va_start`, `va_end`). Instead, Go utilizes multiple ("variadic") arguments via syntax `...interface{}`.
2. The built-in `log` module replaces both `verror` function and `stderr`.
3. For error formatting and presentation, we have used the built-in Sprintf from the fmt package to format our string and any associated variables. The variables them passed using `a...` .
4. The standard `log` lib is typically optimal to deal with recorded errors along with necessary details.
5. Go doesn't support os.strerror or an identical function for system error messages so we couldn’t translate line by line for this '+' as it contains. For a C library call to obtain a textual message for system error code (`os.strerror`), Go lacks this mechanism. It, otherwise should grab Error interface in case of error. Given the nature of returns of C's strerror call, translating it into Go isn't direct.`