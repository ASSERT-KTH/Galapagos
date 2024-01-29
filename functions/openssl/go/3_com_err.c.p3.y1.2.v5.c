In Go, we don't have the exact notion of variable argument lists (varargs) like in C. In Go, we solve this using the special type `...interface{}`. However, Go's "fmt" package provides us with a funct__ion__ __"Sprintf", which can accept any number of arguments to format a string printf-style.

As we don't know the exact type of errcode_t in your code, we are using int for the error code.

Here is the Go equivalent:

go
import "fmt"

func com_err(whoami string, code int, fmtStr string, a ...interface{}) {
    errMsg := fmt.Sprintf(fmtStr, a...)
    com_err_va(whoami, code, errMsg)
}
