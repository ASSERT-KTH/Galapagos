Go language does not support variadic functions the same way as C. Go uses a different approach to handle such scenarios: `...interface{}`. As such, the provided C function cannot be converted to the equivalent Go function that maintains the direct equivalent function signature. 

Due to the absence of pointers to void in Go and the initiation of va_list kind of structure, we can't definitively say we maintain the exact corresponding function design since such function call isn't directly supported by Go's language features. 

However we do a similar operation in Go like this;
go
import "log"

func avLog(level int, avcl interface{}, v ...interface{}) {
    log.Printf(fmt.Sprintf("%s: %s", level, avcl), v...)
}

This function `_avLog_`, utilises Go's notion of interface{} parameter type to refer an arbitrary type and variadic parameters which allow for any length of arguments list.

Note: It is not the equivalent of original function as original function signature is impossible in Go, especially a void pointer doesn't exist in Go. Above function `avLog` will not complie if `fmt.Sprintf` or `Printf` are used as is.