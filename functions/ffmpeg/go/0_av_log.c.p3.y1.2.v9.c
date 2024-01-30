Unfortunately, in the Go language, variable arguments are treated a little differently than in C and don't provide the functionality that the "va_list" functions provide directly.

However, this can be partially implemented to handle the variable number of arguments of type `interface{}` using `fmt.Sprintf` to format variables.

Here's the Go version:

go
import (
    "fmt"
)

type AVCLType struct{}

func avLog(avcl *AVCLType, level int, format string, v ...interface{}) {
    avVlog := fmt.Sprintf(format, v...)
    // Not sure about 'av_vlog' in C code, seems it's a custom function,
    // So to avoid it here, we just print in console or you can adapt the 'av_vlog'
    fmt.Println(avVlog)
}


Please consider this solution with ` interface{} ` as in Go when the type of the varargs elements are not known precisely they use 'empty interface'.
Also 'av_vlog' from C code seems like another custom logging function so I replace 'av_vlog' with plain `fmt.PrintIn` functionality of Golang.

Please replace the `fmt.PrintIn` functionality after bring your 'av_vlog' functionality into Golang.

Minus these exceptions, the rest of your function is transferred as accurately as possible from C to Go. Please note that in Go, instead of using semicolons to close statements, we use newline and compile-time scoped destructor is not present comparable to va_end.