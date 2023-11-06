Due to the inherent differences between Go and C, creating a one-to-one equivalent function can't be done directly with the original function's signature. However, making adjustments with Go's way of handling errors, this could be approximately achieved. We can approximate `com_err` using the `fmt.Errorf` and `fmt.Printf` functions:

In contrast to C, Go doesn't support variadic arguments the same way. So, while the `fmt.Printf` & `fmt.Errorf` function provides similar functionality, passing a `va_list` directly isn't an option. Instead, Go uses a slice (`...interface{}`) for this purpose.

Here might be a reasonable approximation:

go
import (
	"fmt"
)

func ComErr(whoami string, code int, fmtStr string, a ...interface{}) {    
    fmt.Printf("%s ", whoami)
    if code != 0 {
        fmt.Printf("(Error code: %d) ", code)
    }
    fmtStr = fmt.Sprintf("%s: %s\n", whoami, fmtStr)
    fmt.Printf(fmtStr, a...)   
}


First, we've changed `errcode_t code` to `int code`, since Go doesn't have an `errcode_t` built in. Ideally `int code` should be an enumerated type or similar custom type, which again there's no direct mapping.

The variadic arguments (`...`) are different than how it's done in C; in Go a new slice of `interface{}` is created. In C a pointer to the arguments is created—which really is objectively superior since it doesn't require creating a huge, potentially completely unneeded, slice in memory.

The last difference of course, is change in function call. In the original com_err, it is calling a previously defined variadic function with `com_err_va(whoami, code, fmt,ap)`. Since this doesn't have a straight forward implementation from C to Go, approximation is done with `fmt.Printf` instead. We print first the name followed by fmtStr.