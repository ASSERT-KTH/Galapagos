Since Go does not support variadic functions in the way C does, the function cannot be translated with exact semantic equivalence without changing interfaces or the function signature. Variadic arguments must be of a specific type in Go. Nevertheless, it can still be ported to Go if some assumptions are met. 

Here's the Go function, assuming that all variadic arguments will be of type interface{} and `av_vlog()` are valid Go functions.

golang
import "fmt"

func avLog(avcl interface{}, level int, format string, v ...interface{}) {
    avVlog(avcl, level, format, v...)
}


As `fmt.Sprintf(format, v...)` can parse the formatted string, if `av_vlog` function handles only formatted strings, you can change `av_vlog` accordingly:

golang
import "fmt"

func avLog(avcl interface{}, level int, format string, v ...interface{}) {
    avVlog(avcl, level, fmt.Sprintf(format, v...))
}
