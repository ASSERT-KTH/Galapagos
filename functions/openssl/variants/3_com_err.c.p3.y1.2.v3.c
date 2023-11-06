It's unfortunately impossible to provide a semantically identical Go version of the C com_err() function. Go does not support var-arg functions in the same way that C does. C allows you to specify optional additional arguments using "..." , referred to as variadic arguments.

In Go, we can specify variadic functions which accept an arbitrary number of arguments with the same type, but go variadic arguments do not support arbitrary types or formats, which can be used in C. 

Although, The fmt package of Go which gives you Printf that works almost like the C's print. func Printf(format string, a ...interface{}) (n int, err error). But retrieving semantically equivalents in other packages or standard libraries is difficult.

In general, if you try to convert a function from C to Go, you have to reconsider how this function should behave in terms of Go's design, convention and capabilities. This is same with error reporting or handling since Go has its own way with the concept of multiple return values.

Below is a hypothetical Go version of the C function, which simulates as closely as possible how "com_err" might work if Go's ""fmt" package behaviour is closest match for variable argument handling but the type handling is not be possible to inherit:

go
import "fmt"

func ComErr(whoami string, code errcode, fmtStr string, args ...interface{}) {
    fullStr := fmt.Sprintf("%s: %s: %d", whoami, fmtStr, code)
    fmt.Printf(fullStr, args...)
}

Few important points to be noted. C has an errcode_t generic error type which may be represented by an int error code or error struct{ errno int, message string Etc..}, eitherway a similar shoul define in general context if needed.Should also note is - imported from “C”(without dquotes), that's – in CGO way - generally used to access standard libraries but will fails in specific Scenerios, in statically linked go programs with C libraries.