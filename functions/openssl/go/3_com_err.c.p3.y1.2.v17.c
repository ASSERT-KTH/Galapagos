In Go, variability of argument numbers such as that provided by ellipsis (...) in C isn't recommended, and variadic functions in Go work quite differently than their C counterpart. Moreover, types like "errcode_t", helper methods like "va_start", "va_end", and "com_err_va" do not exist in Go. Thus, there isn't really exact porting of such a functions to Go.

However here is representation in Go, which interpret the concept but wouldn't be semantically equivalent.

go
import (
    "fmt"
    "log"
)

func ComErr(whoami string, code error, fmt string, a ...interface{}) {
    if code != nil {
        log.Printf("%s: %v", whoami, code)
    }
    log.Printf(fmt, a...)
}


This is the best possible conversion to idiomatic go which isn't exactly similar to the C function but following the Go's practise, without extra auxiliary function with the expected error handling and variable arguments.

In here "whoami" is a string, "code" is an error that will represent the equivalent for "errcode_t",  the "fmt" is a string format and "a" represents variadic arguments which will be passed on. These variable arguments ("a...") work differently from C-style ellipsis ("...") argument, as 'a' is actually a slice of values instead of true variable arguments. During executing Printf function it is expanded to match the version function.