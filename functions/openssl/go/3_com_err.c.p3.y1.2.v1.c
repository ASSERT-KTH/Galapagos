Go does not have variadic macros/constants nor does it directly support C's whole `stdarg.h`. As such, an exact conversion isn't quite possible with Go's limitations. However, composing analogous signature by using the general spirit of the function in Go we get:

Go
import "fmt"

func com_err(whoami string, code error, format string, a ...interface{}) {
    fmt.Printf("%s %v "+format, append([]interface{}{whoami, code}, a...)...)
}


Note that the error code and other elements from `fmt, ...` in C is treated as an `error` and `variadic interface` respectively in Go and gets printed inside `%v` and format using `fmt.Printf()`. Auxiliary errors and fully varadic error messages using the C variadic args equivalent in Go can be combined in similar ways within the Go constraints.