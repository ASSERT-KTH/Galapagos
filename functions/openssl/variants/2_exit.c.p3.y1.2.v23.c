Go does not provide direct support for overriding the built-in `exit` function and sleeping for microseconds as in the provided C code. However, as far as possible given Go's constraints, a similar idea could be achieved as follows:

go
import (
    "os"
    "time"
)

func exit(status int) {
    time.Sleep(100 * time.Millisecond)
    os.Exit(status)
}


In this Go example, the `time.Sleep()` function is used to pause execution for 100 milliseconds, equivalent to the provided 100000 microseconds, then the `os.Exit()` function used to terminate the program with a given status code.

Remember, the sleep before the exit is generally not needed or recommended for most Go programs, this representation is just to mirror the original C code. If you must replicate this behavior, consider using the defer os.Exit.