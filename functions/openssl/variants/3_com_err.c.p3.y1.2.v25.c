Unfortunately, it's not possible to have a 1-to-1 translation of the C function to Golang.

One particular issue is handling the variadic arguments that only has a single base type, which even then is passed to the function 'com_err_va'. Va_list and the associated functions - va_start, va_end are specific to C and there is no equivalent construct in Go, which means such argument handling can't be done.

More importantly, Go does not support function overloading, further causing problems for implementing this kind of functionality. However, you can emulate the passed variable parameters by using the empty interface type interface{} in Go, but the caller of the function needs handle types appropriately. Furthermore, in Go, function calls are not usually error-checked like they are in C.

Here's a general conceptual translation where args is used to represent the variable arguments equivalent of "...":

go
package main

import (
    "fmt"
)

func ComErr(givenError error, args ...interface{}) {
    if givenError != nil {
        fmt.Println(givenError)
        for _, value := range args {
            fmt.Println(value)
        }
        
    }
}

Notice that I used a Go error type instead of 'errcode_t' and 'const char', since there is no strict equivalent in Go and that typed errors are idiomatic to Go.

Again, please note that the utilisation of Golang error type is illustrative, you need to find the right type to match your 'errcode_t' in your expectations. Additionally, understand that the placeholder fmt method will work just fine as long as the final expected result of your 'fmt' parameter is effectively a string.