It is not entirely possible to emulate C's varargs exactly in Go; however we can come pretty close by taking advantage of Go's variable-length argument handling. Unfortunately, complete conversion is not possible due to differences in language semantics and in the way these two languages deal with user input, errors, and strings.

Below is the converted code, convenient for understanding:
go
import (
    "fmt"
)

func com_err(whoami string, code int, v ...interface{}) {

      fmt.Printf(whoami + " ")

      for _, arg := range v {
        switch arg := arg.(type) {

            case int:
                fmt.Printf("%d ", arg)

            case float64:
                fmt.Printf("%.2f ", arg)

            case string:
                fmt.Printf("%s ", arg)
        }
    }

    fmt.Printf("%d ", code)

    fmt.Println()

}

This will not handle formatting what so ever. More sophisticated printing, context or error handling should be developed on your own, since it can be more than complex.  

Noted that: this function usage would change slightly so to use `com_err` call in `Go` it will change to `com_err("nameOfStringToPrint", 1, list..., "of variable argument", "you want to use", "up to n strings")`. This is semantically equivalent for given `code` C function with respect to `Go` related functionality. Also error-handling in this function only uses exit statuses, where `1` denotes an error, and `0` denotes no errors. This diverges from the extensive error-handling capacities detailed in the `*nix com_err error-handling library. You could craft a more suitable, equivalent function relating to Go's error functionality from scratch. Error handling can widely vary based on the type of the project requirements. However, this is not the absolute alternative for complete conversion which may or not handle `fmt` along with variable argument list syntax of Go effectively.