In the Go programming language, we do not have equivalent keywords for `va_start`, `va_end` and `va_list` as those are specific to some languages like C and C++. However, a very similar mechanism can be used by passing on a "`...interface{}`", which indicates that we can pass an arbitrary number of arguments of any type into the function. 

The reason behind avoiding the issue of variable arguments in Go is mostly to encourage clear, idiomatic code that specifies the exact types required. Still, for completeness, here is a go function using variadic arguments:

go
import (
	"log"
	"fmt"
)

func av_log(avcl interface{}, level int, fmt string, v ...interface{}) {
	s := fmt.Sprintf(fmt, v...)
	log.Println(s)
}


In this code, `v ...interface{}` essentially captures all additional arguments provided, which you can then treat as a slice inside the function if required.