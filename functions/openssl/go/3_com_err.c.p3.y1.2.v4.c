The Go standard library doesn't provide such level of compatibility with C and its variadic parameters functionality is somewhat limited in comparison. That said, there's still no direct translation to this as Golang doesn't support the va_end, va_start, etc functionality as it accepts variadic arguments differently. 

However, similar functionality can be achieved. Here's an equivalent version of the function in the Go programming language:

go
package main

import (
    "fmt"
    "log"
)

func ComErr(whoami string, code int, format string, a ...interface{}) {
    log.Printf("%s: code %d: %s", whoami, code, fmt.Sprintf(format, a...))
}


This function takes as parameters a string whoami and an object of type `error`, an error code of type `int`, along with a format string and follows log.Printf behavior for variadic arguments. It concatenates the `whoami` string and the error, then logs the result, fulfilling the similar purpose to the original C function.

Remember that Go doesn't have something completely equivalent to `errcode_t` from the C programming language. We anticipated that `code` should be an integer type, so you would want to tailor it to your use case before using the function.