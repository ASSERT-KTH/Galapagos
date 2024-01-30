In Go, it's not possible to emulate the whole function because `errno`, `fflush`, `clearerr` and `error` are all C-specific features and the use case is meaningful in C where system-level control is really needed. These specific functions in the original code are essentially about system error handling in C that are cared very differently in Go -- usually, error handling in Go is done directly because Go believes in simplicity and readability (i.e., directly resulting errors rather than using error codes or global variables like `errno`).

However, if you want to exit with a failure on a write error, you can use os.Exit in Go because it makes the current process exit with given status.

Let's say we have an error and a message and you want to display it and exit. The Go equivalent could look like this:

go
import (
    "fmt"
    "os"
)

func writeError(err error, msg string) {
    fmt.Fprintf(os.Stderr, "%s: %v\n", msg, err)
    os.Exit(1)
}


This is not an equivalent of the original C code provided, it's an interpretation. If you're translating C to Go for an existing system, it would require a proper understanding of the system and close co-operation with the stakeholders / developer
because the idiom how to deal with errors is significantly different between Go and C. You shouldn't try to imitate C-style error handling in Go.