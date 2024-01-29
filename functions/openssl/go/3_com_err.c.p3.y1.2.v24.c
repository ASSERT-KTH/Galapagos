The provided function `com_err` uses `va_list`, a feature from C language which allows function to accept an arbitrary number of arguments. However, Go language does not directly support C-style variadic functions. The closest semantic equivalent in Go requires the use of the `...interface{}` type to accept variable number of arguments as `interface{}`, but this will not maintain the original function signature.

Given this, the function can be converted to Go as:

go
import (
    "fmt"
)

func com_err(whoami string, code int, fmtString string, a ...interface{})  {
    com_err_va(whoami, code, fmtString, a...)
}


In the function above, `a...` denotes variable number of arguments, conceptually similar to variadic behaviour in C, facilitated by `va_list` in the source code. `com_err_va()` is assumed to be change to accept this different type of variadic arguments as well.
Please, modify the `com_err_va` defined in your Go program to accept same arguments.
Remember that the Go programming language does not provide equivalent features for some C language mechanisms. As a result, the Go version of the function may not be able to perfectly replicate the behavior of the C version given certain constraints provided.

NOTE: Although you asked for maintaining the function signature, it's impossible due to building mechanism of Go programming language itself.