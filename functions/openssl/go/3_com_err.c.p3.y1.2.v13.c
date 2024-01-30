Implementing a semantically equivalent version of the `com_err` function in Go is quite difficult as Go does not directly support myriadic (or ... notation) arguments initially. However, Go provides variadic functions that can work with an arbitrary number of arguments, which can be passed using the `...interface{}` type. As C's varargs are untyped, equivalent behavior can be approximated, though specific type handling to actually utilize the values is outside the scope of this conversion itself.

Another point is that Go does not include a builtin error equivalant to C’s errcode_t, the equivalent err might just be an integer or it could almost be a struct that implements the error interface. Though it will never be a perfect equivalent without additional information.

A possible Go implementation might look like this:

func com_err(whoami string, code error, format string, a ...interface{}) {
  msg := fmt.Sprintf(format, a...)

  // Implementation
}

An alternative approach with a simple int error:

func com_err(whoami string, code int, format string, args ...interface{}) {
  fmt.Printf(format, args...)
  // Rest of the function implementation
}


Methods `va_start`, `com_err_va` and `va_end` are coming from C standard library (stdarg.h), they do not exist in Golang.

Final note, you can avoid this conversion, just to use CGO:
https://golang.org/cmd/cgo/