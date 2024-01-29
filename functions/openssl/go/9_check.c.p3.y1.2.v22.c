Unfortunately, the Kerberos 5 (krb5) library isn't natively supported by Go, thus some direct translations may not be possible. Instead, we may repurpose the function to the scenario where error handling is needed in Go language and keeping as much similarity as possible. However, concerning type `krb5_error_code` and functions like `krb5_get_error_message()` and `krb5_free_error_message()`, those cannot be used directly on Go. 

On Go language we'd resort to the `error` built-in interface to accomplish the same kind of behaviour. Here's a possible version:

go
import (
    "fmt"
    "log"
    // ... additional imports
)

func check(code error) {
    if code != nil {
        log.Println(code.Error())
    }
    if code != nil {
        panic(code) // usage of panic is recommended to replace assert.
    }
}

  
Please note the Go's idiomatic way to handle errors is by comparison to `nil`, rather to a `0` value in many C implementations. Furthermore, Go language does not have any `assert` function similar to C's assert macro. You'd commonly see the `panic()` function being used in this context.  Also bear in mind it's generally frowned upon, unloading control out of the program like this in most of the circumstances, so use it consciously.