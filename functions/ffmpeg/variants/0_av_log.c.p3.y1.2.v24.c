Go does not directly support variadic arguments of different types in a single function so the log function will take different approach:

In Go, the `log` package handles this using a `Printf` style argument list, which could be a good alternative here. This allows the user to maintain a somewhat fluent syntax when logging.

go
import "log"

func avLog(avcl interface{}, level int, fmt string, v ...interface{}) {
    // Simulates the level priority
    if level < 3 {
        return
    }
    log.Printf(fmt, v...)
}


This method accepts a `format` string, and the `..` tells Go to take zero or more arguments of this type (i.e., `interface{}` which you can think of as any type) and create a slice of those values.

Please note this is not a 1-to-1 port of your original C function, But Variadic function in the Go programming language behaves somewhat differently than C-based software, allowing you to create much safer and easier-to-use features by avoiding some complexities.

Thus, the exact C function cannot be replicated in Go due to these:
- Absence of va_args equivalent in Go.
- Go is more Type Strict than C. It does not implicitly cast types.
- No pointers passed to the function as argument. Go discourages of it due to safety.
Therefore this Go implementation logs all arguments provided using the `log` package's `Printf` function using all arguments that follow the format.