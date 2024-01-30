Your C function uses `krb5` library and `assert` function to show error messages and halt program execution if an error occurs. In the Go language, we don't have exactly identical counterparts to those libraries and behaviors. However, `errors` package and `panic` function can give semantically similar outcomes. Here is the code equivalent to your requirements:

Go
import (
    "errors"
    "fmt"
)

// ErrorMessage function substitutes krb5_get_error_message function in Go for demonstration.
func ErrorMessage(ctx, code interface{}) error {
    // Define your errorMessage acquisition behavior. It might or might not use ctx.
    return errors.New("Your error message")
}

func Check(code int) {
    var errmsg error

    if code != 0 {
        errmsg = ErrorMessage(nil, code) // Here we are sending nil as we don't hold krb5 context in Go
        fmt.Println(errmsg)
    }
    if code != 0 {
        panic("Assertion failed!") // panic acts similar way as assert() does in C
    }
}

Please note that Go does not provide a krb5 equivalent like C's libkrb5, so we simulate ErrorMessage() operating similarly for illustrative completion. You need to replace it with a concrete definition corresponding to your case

Also, please note the context (ctx) which was likely an krb5_context object in your original code. My answer's code discards it as there's no direct semantic translation inside Go. You'd need your proper krb5_error_message analogue function instead, depending on which library or service you'll use to replace that dependency. After implementing this function, you can add context as a parameter in a needed manner. 

Alternative implementation for stop execution to mimic asser

Go
if code != 0 {
    log.Panic(errormsg)
}

This will print the error message and additional information about position in source code where panic was invoked and stop execution.