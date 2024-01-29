In Go, we cannot create a direct equivalent of the `av_log` function because arguments passing mode is different from the way it is in C and includes no support for var arg in patterns utilized by c-libs (va_list). 

However, we can utilize `(v ...interface{})` ellipsis for variadic inputs as an alternative. Also, in Go, point a function tends to `interface{}` rather `void *`.

By using format and logging library we can mimic the same function in Go. 

Based on these constraints the closest equivalent in go would look something like this:
go
package main
import "log"

func avLog(avcl interface{}, level int, format string, v ...interface{}) {
    log.Printf(format, v...)
}

Log.Printf has similar behavior to the c print function by accepting formatting directive and the substitute variables as trailing arguments. 

For an exact port (va_list like) of this c syntax, additional mechanisms like CGO can be used but the resultant complexity is generally unnecessary.