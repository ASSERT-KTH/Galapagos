Due to significant semantic differences between C and Go, creating a Go function with the exact same signature is impossible. However, here's a simple version using Printf for formatted output in Go:

go
import (
	"log"
)

func avLog(avcl interface{}, level int, format string, v ...interface{}) {
	log.Printf("%v %v "+format, append([]interface{}{avcl, level}, v...)...)
}

Note:
1. The `...interface{}` seen in the Go function signature is Go's way of dealing with variable number of arguments, equivalent to `...` in the C function.
2. `Printf` will interpret and format string according to the format specifiers.
3. As Go doesn't have equivalent facilities of `stdarg` in C for manipulating the arbitrary number of variables following a certain argument, we cannot exactly mimic the method `va_start(`, `va_end`, and `va_list`. However, passing data into function encapsulated in `v ...interface{}` gives us similar capability.
4. Interface{}(any type) is used in replace for `void*`. It allows function to accept parameter of any type.

Be aware that:
The way how to use parameter avcl and level depends upon their concrete types and semantics within your actual code, the conversion demo above is just a general guess.