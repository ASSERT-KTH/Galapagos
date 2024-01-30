Rewriting the exact function from C to Go is not possible because Go does not have similar facility like variadic functions in C. Also, Go language doesn't have a direct equivalent of 'errcode_t' in C used for carrying specific error info. But we can create a similar function, using 'error' type provided by Go. Here is what a **rough equivalent function** could look like:

go
import (
    "fmt"
    "log"
)

func com_err(whoami string, code error, args ...interface{}) {
    if code != nil {
        log.Printf("%s: %v", whoami, code)
        // handle additional format string and variadic arguments
        if len(args) != 0 {
            if format, ok := args[0].(string); ok {
                log.Printf(format, args[1:]...)
            }
        }
    }
}


In the function `com_err`, we made it possible to accept a variety of different arguments with `...interface{}`, which is similar to "..." in C. Although a Go program wouldn't typically use an "error code", an error can be customized much more fully than an error code typically would be in C, making it an okay substitute for 'errcode_t'. 

Please note, Go’s way of error handling and reporting are significantly different than what is commonly done in languages which support exceptions, so trying to copy style from such a language to Go would likely only yield problems.