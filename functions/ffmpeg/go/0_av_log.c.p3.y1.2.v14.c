The Go programming language does not directly support variadic arguments similar to how the va_list is used in C programs. In Go, things do require some more work and be explicit. 

However, below code is the closest analog in Go. The "fmt" argument, and practical variability of it has not been reflected into any variable in the go code conforming to limitations as presented by the prompt overall.  

go
package main

import (
	"fmt"
)

func av_log(avcl interface{}, level int, formatter string, val ...interface{}) {
	av_vlog(avcl, level, formatter)
}

func av_vlog(avcl interface{}, level int, formatter string) {
	// handle variadic arguments
}

In the snippet above:`val...interface{}` represents an unlimited number of arguments as variadic arguments, but it does ignore how the user will input format string (fmt). If you want user to the define format like in printf you will change your approach little differently and switch placeholders to `%v` as it stands for value in `fmt` methods:

go
package main

import (
	"fmt"
)

func av_log(avcl interface{}, level int, val ...interface{}) {
	av_vlog(avcl, level, fmt.Sprintf("%v", val...))
}

func av_vlog(avcl interface{}, level int, txt string) {
	// handle variadic arguments
}

And of course each of the fmt method like - Printf, Sprintf etc. bring their own interpretation to the data and placeholders, and hence could eventually give different output rendering than original C-style printf.