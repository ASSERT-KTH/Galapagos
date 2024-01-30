In Go language, variable argument functions are expressed by appending "..." to the type of the last parameter. Furthermore, the C function `va_list` doesn't directly correspond to any built in Go types. So instead, we use the type `[]interface{}` and the `...` suffix in Go which will accept arbitrary number of parameters.

The equivalent Go code would look something like:

go
package main

import "fmt"
import "os"

func com_err(whoami string, code error, format string, a ...interface{}) {
    fmt.Fprintln(os.Stderr, fmt.Sprintf(whoami+": "+format, a...), "\nError code: ", code)
}

Above Go code is a semantic equivalent of given C function, While accounting for Go's different syntax and error/use of the `fmt` package functions. Note that Go has a built-in `error` type, which fits well with the `errcode_t` parameter from the C code. Furthermore, instead of starting a variable argument list with `va_start` as in C, we declare in the signature of the Go function that it accepts a variable number of arguments with `...interface{}`.

This `com_err` function then treats the these variable parameters as arguments to the string format function. It then writes these formatted strings out with the error code to os.Stderr to mimic the error reporting of the C function.  Do note, that this basic implementation does not include extra error handling or behavior. `fmt.Fprintln` takes care of adding a newline character to the print statement, similar to how most C programmers use `fprintf`.  

Please note: The actual translation can depend specifically on what `com_err_va` does in your C code which isn't provided here.