Go doesn't support arbitrarily long argument lists like C ("variadic functions"), and log isn't part of the reflect or main packages. If design is open for change, use the standard `log` package, combined with Go's version of variadic functions.

Here's how you might translate the function:

go
import "log"

func avLog(avcl interface{}, level int, format string, v ...interface{}) {
    log.Printf(format, v...)
}


This changes the function signature, but should have the same behavior under most circumstances. As you see, we essentially use `Printf` from Go's `log` package which can take a format string followed by an arbitrary number of arguments (`v...`). Hence the function's behavior from a user's perspective remains the same.
Usually we would’ja use variadic function to log messages where we are dealing calls and need to relay or log same messages to multiple different locations without knowledge of how to do so. In go we usually achieve that using Printf() and its derivatives.