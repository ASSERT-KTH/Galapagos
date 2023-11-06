Go doesn't support variadic functions in the same way as C, so porting this function directly isn't completely achievable. However, equivalent functionality can be implemented with the "fmt" package: 

go
import "fmt"

func comErr(whoami string, code error, format string, a ...interface{} ) {
    msg := fmt.Sprintf(format, a...)
    fmt.Print(whoami, code, msg)
}


In Go, as opposed to C, "a ..." is used to create a variadic function, or a function that can accept a variable number of arguments. This is particularly useful when you would want to pass a number of arguments without specifying how many there will be.

Please note that error handling in Go is done a bit differently than in C. You would usually not combine an error code and error message in a single function but handle them separately, both at throwing/catching and printing/logging. 

In real scenarios Go, we use predefined package level errors for error code functionality, or we create a custom type that defines an Error method. Ultimately we handle error message and supposed error codes distinctly. 

If there is a standard you're following where comErr as such needs to be defined, then you could work towards organizing your code to adapt to Go's standard error handling. The given code will work, but it's important to be aware that direct varargs conversion isn't possible due to language differences and idiomatic Go Code practices encorage a different style for error handling.
