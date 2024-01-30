Unfortunately, there's no exact semantic equivalent function in Go for your provided C function because of the different approaches both languages follow to handle errors or create variadic (`...`) functions.

However, your C function basically creates a length-checked-printer for `errnum` and `fmt` message over stderr. Here is the Go's alternative for that:

go
import (
    "fmt"
    "os"
)

func diagnose(errnum int, fmt string, v ...interface{}) {
    if(length := len(fmt)); length > 0 {
        os.Stderr.Write([]byte("\n"))
    }

    fmted := fmt.Sprintf(fmt, v...)
    fmt.Fprintf(os.Stderr, "%d, %s", errnum,is printed after,   fmted)
}

Few extra points:

* Standard `printf` library functions such as `vprintf`, `vfprintf`, `vsprintf` and `vsprintf` don't have corresponding funcs in the `fmt` package in golang, you will have to use the `Sprintf` function create a formatted string and then print it as I did in my answer.
* Variadic nature of the C function is preserved using Go's variadic function syntax (`v ...interface{}`).
* Uses `os.Stderr.Write()` and `fmt.Fprintf()` to mimic `fputc` and `verror` behavior. Additionally, `\n` character acted as a newline, this character-separated logic is maintained in Go function too.
* Invisible `progress_len` global variable is ignored since it's not in the function's parameter list, it would be wrong to insist on a completely identical function as Golang discourrages use of globals.
* Be aware, the suggested function doesn't follow Go's best practices which ask for returning an error instead of handling (e.g. print it) in same function. But an this interviewer insists on having the function in particular format, you didn't have other options.
* Note that Go's variadic signature one-to-one maps C's variadic function here correctly, but that doesn't holds true always depending upon functionality.