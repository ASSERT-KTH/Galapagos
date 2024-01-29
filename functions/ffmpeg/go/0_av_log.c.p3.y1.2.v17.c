Go does not formally support variadic arguments in the same way C does. However, it has an alternative construct using an ellipsis [...] after the type instead of using ... before the argument variable (like in C). Here's an equivalent implementation written in Go.

go
import "fmt"

func av_log(avcl interface{}, level int, format string, a ...interface{}) {
    s := fmt.Sprintf(format, a...)
    fmt.Printf("%v %d %s\n", avcl, level, s)
}


In the Go version, `interface{}` allows `avcl` to take on any type, replicating the function of `void*` in C. The variadic `...interface{}` for `a` lets our Go function be called with any number of arguments of any type following `format`, just like the `...` in your C function.

One implication of this change is that due to the format string interpretation issue, the Go function would fail at runtime if the arguments didn't match the `format` string, whereas the C version would likely fail at compile time.

Therefore, this Go function is not an exact conversion of the C function, but it's fairly close approximation given language constraints.