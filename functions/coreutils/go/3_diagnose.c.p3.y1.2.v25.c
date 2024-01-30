Unfortunately, a direct translation of the original function from c to Go is not feasible due to the lack of support of varargs macro equivalent to va_list, va_start, va_end and verror (a function in GNU C library for reporting errors) in golang.

Golang promotes the use of multi-valued returns, instead of passing variables by reference. Errors are typically handled as a distinct return value, unlike C, which conventionally uses an int as an error code in the function's signature. 

However, the 'fputc' part where it prints '\n' on stderr, when variable 'progress_len' > 0, can be equivalent translated to:

go
package main 

import (
    "fmt"
    "os"
)

var progress_len int // assuming this comes from your previous Go code 

func diagnose(errnum int, fmt string, v ...interface{}) {
    if progress_len > 0 {
        fmt.Fprintln(os.Stderr, "")  
        progress_len = 0
    }
    // Report errors using os lib instead of verror C function.
    emsg := fmt.Sprintf(fmt, v...)
    fmt.Fprintln(os.Stderr, emsg)
}

In Go programming language, package 'fmt' provides Printf variants (like Sprintf) which format string as per format specifiers with capability to interpolate multiple values into string which can be equivalent to how var-arg used in C's printf like functions(C stdio or sprintf).

Again for Error handling in Go, error lines can be emitted to 'StdErr' file descriptor using os package instead of verror C library function. However the error handling with distinct error codes are not explicitly instructed that can follow mechanism dealing with 'error' type in Go language as best practices. Such error handling feature is based on the actual internal flow status into consider to convert the semantic from C to Go just based on the diagnosing intent-functionality.