It's impossible to maintain the original function signature due to the differences between C and Go with respect to variadic function and handling of errors. Below is a semantically similar function in Go considering Go's way of handling errors along with variadic input.

Go:

go
import (
    "fmt"
    "log"
    "os"
)

var progressLen int

func diagnose(errnum int, fmt string, a ...interface{}) {
    if progressLen > 0 {
        fmt.Fprintln(os.Stderr, "\n")
        progressLen = 0
    }

    log.Printf(fmt, a)
    if errnum != 0 {
        log.Fatal("Error:", errnum)
    }
}


Please notice:

1. Go doesn't uses header files. Importing used packages is the standard routine.
   
2. Go doesn't support method overloads or default arguments. You can mimic that feature using variadic functions (using ...interface{} to accept any number of arguments), but you must handle the type assertions inside your function.

3. Printing to stderr with fputc would require the usage of the fmt and os package in go, which is shown in the sample code.

4. varargs and va_lists translate into using interface{} and reflect package in Go.

5. In Go, generally errors are not integers but of the predefined type error.

From above observations, it's obvious that semantically similar function and exactly same semantics in terms of arguments are impossible due to these languages being very different in the way they handle errors, type system and lack of several concepts in Go which are implemented using other mechanisms.