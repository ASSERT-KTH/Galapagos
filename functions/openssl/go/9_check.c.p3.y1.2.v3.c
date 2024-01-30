There isn't a direct equivalent in Go for the `krb5_get_error_message` and `krb5_free_error_message` functionalities used in the C code which are part of Kerberos library and `assert` function in C which stops execution if the condition is false. However, there is a way to throw an error in Go is like this:
go
package main

import (
    "fmt"
    "log"
)

func check(code int) {
    if code != 0 {
        log.Fatalf("Error code: %d\n", code)
    }

    if code != 0 {
        panic(fmt.Sprintf("Assertion failed: %d\n", code))
    }
}

This code prints an error message with the code if it is not 0 as in the initial code. The `log.Fatalf` function is equivalent to `printf` followed by a call to `os.Exit`. It also provides the timestamp when the error occurred. The `Fataf` function also calls `panic` if the error code is non-zero, equivalent to `assert` in C.

>Please Note: Error handling in Go is usually done using `error` rather than relying on `panic` and `recover`.  This solution is based on the direct conversion of your concepts despite them not being idiomatic Go.