The Go language does not support varargs like C so you cannot convert this function directly to Go with the original function signature intact.

However, we can create a similar function in Go using the `...interface{}` in Go which enables us to pass an arbitrary number of arguments of arbitrary types.

Go
import "log"

type AVCL struct{}

func AvLog(avcl *AVCL, level int, fmt string, v ...interface{}) {
	log.Printf(fmt, v...)
}


Note: This version inspired by Go's logging package and is semantically different from C's varargs which accepts a list of arguments of the same type specified by a prior argument. Git's varargs allow arguments of any type and each argument carries its own type information. 

The `log.Printf` function is used to print the function parameters to the standard logger with the specified format. Each operand to `fmt.Printf` is immediately followed with an identical argument that carries type information for the previous operand. 

This implementation loses any special logging applied to the `avcl` and `level` arg. 

To handle this, further implementation specific to your use case would be required. It may include, for instance, customized logging levels your application workflows. You may use the AVCL and level arguments in conjunction with a specific logger to provide more nuanced behaviour conforming to your own software specifications. 