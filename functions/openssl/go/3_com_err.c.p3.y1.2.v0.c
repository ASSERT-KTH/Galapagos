Go does not support functions with variable argument length exactly as C. There is no direct Go equivalent to C's "..."which could allow multiple arguments of different data types. Instead, Go provides a solution named "Variadic Functions", which takes  variable number of arguments but all of the same type. 

Also, Go does not support direct error code handling as in C (errcode_t type does not exist in Go), but it uses the built-in interface "error". Instead of returning error codes, it is idiomatic in Go to return error as a second return value.

Thus a direct translation maintaining the function signature isn't plausible owing to fundamental differences between language features and design, but approximating based on assumptions, let's consider the below example where `com_err` function takes a `whoami` string as the first argument, an error code which is sent in `code` object of `Error` interface (you can customize it the way you want), `fmt` format for final string (as the first value for `fmt.Fprintf`) and other arguments as interfaces (`arg ...interface{}`).

go
import (
    "fmt"
    "os"
)

type Error struct {
   Name        string
   Description string
   Code        int
}

func (e *Error) Error() string {
    return fmt.Sprintf("%s: %s", e.Name, e.Description)
}

func com_err(whoami string, code *Error, format string, arg ...interface{}) {
    appendedString := fmt.Sprintf(format, arg...)
    finalString := fmt.Sprintf("%s %v: %s", whoami, code.Code, appendedString)
    fmt.Fprintln(os.Stderr, finalString)
}

Please replace `os.Stderr` with the required I/O operations as per your use case. This is just a reference and you may need to customize the function for exact needs. It's a transformation but do keep Go does not provide character-to-character translation from C.