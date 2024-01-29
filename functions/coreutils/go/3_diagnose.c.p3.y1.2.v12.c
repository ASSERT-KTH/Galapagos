Given that Go does not include direct support for variadic arguments in the style of c's <stdarg.h>, there's no one-to-one equivalent recipe to implement this function.
Also, Go does not include exception builtin support.
The interface{} type used below to process variadic parameters are the equivalent of (void *) in C.

The purpose of this function, given that *stderr is suggested to make use, it seems like it should emit an error message.

Maintaining semantic functionality here is complex due to variable args (fmt, ...) given.
As we can see it looks if there is an error and outputs what occurred creating kind of a log.

Below code is an attempt to mimic the behavior with closest equivalents, our Go's function here would look something like:


package main

import (
    "fmt"
    "os"
    "errors"
)

var progress_len int64

func diagnose (errnum int, fmt_word string, a ...interface{}) {
    if progress_len < 0 {
        fmt.Fprint(os.Stderr, "\n")
        progress_len = 0
    }

    if errnum != 0 {
        errMsg := fmt.Errorf(fmt_word, a...)

        // write the error to stderr 
        fmt.Fprint(os.Stderr, errMsg)
    }
}
