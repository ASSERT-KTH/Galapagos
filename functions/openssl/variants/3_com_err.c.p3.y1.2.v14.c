In Go, unlike in C, you can't call a function with a variable number of arguments in the way that `com_err_va` is called, so the functions with a variable number of arguments will be defined and used in another way.

The equivalent function in Go can't maintain exactly the original function's signature, due to differences in how Go and C handle certain coding constructs such as variable argument lists, pointers and their error handlers. The Go version is as follows:

go
package main
import "fmt"

func com_err(whoami string, code error, a ...interface{}) {
    
    msg := fmt.Sprint(a...)

    if code != nil {
        fmt.Printf("error: %s, %v, %s\n", whoami, code, msg)
    } else {
        fmt.Printf("%s, %s\n", whoami, msg)
    }
}


In the implementation above, `com_err` is a Go function that outputs the `whoami` and `msg` as a prefix to `code`. The ellipses (...) used in the `a ...interface{}` variation indicate that you can give 0 or more of these arguments to this function. 

Also note that in Go, errors are values which have a built-in error interface, just like how an int64 has the built-in int64 type. So, instead of trying to simulate the flexibility of C's preprocessor by checking if error types are passed with integer, we implement the code which checks if an error causing part actually exists as illustrated by `if code != nil`.