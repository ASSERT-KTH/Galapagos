Unfortunately, krb5 library functions used in the provided C code aren’t readily available or have equivalent functions in Go. However, here is a translation that maintains the basic function or feel of the C version. It takes an error instead of error code, prints its message to the standard error output (if the error is not nil), and panics if the error is not nil.

go
import (
    "fmt"
    "os"
    "errors"
)

func check(err error) {
    if err != nil {
        fmt.Fprintln(os.Stderr, err.Error())
        panic(errors.New("An assertion failed: err must be nil, not " + err.Error()))        
    }
}


Though, note the differences:

- `panic` in Go doesn't equal `assert` in C. Strictly speaking, Go does not provide an `assert` keyword or function that directly corresponds to `assert` in C. What's done here with `panic` bothers on idiomatically unlike Go style.
- The error handling philosophy in Go typically includes passing error values explicitly.

Remember this is an rough equivalent at best, not a direct translation. An exact translation would necessitate evoking methods equivalent to `krb5_get_error_message` and `krb5_free_error_message`, operations for which doesn't have matching versions in Go. That level of parallelism with your C code isn’t possible without involving lower-level operations like syscalls or using CGo to bind to C libraries - which are main topics by themselves.