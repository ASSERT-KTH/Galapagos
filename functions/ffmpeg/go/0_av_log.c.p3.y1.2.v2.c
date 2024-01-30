In Go, there is no analog to varargs (`...`) of C and with respect to `void*`, everything in Go is pass-by-value. But, we can try to mimic the function call graph in C code. However, it's necessary to label types explicitly in Golang so it might not be a exact transfer in a real world use case. 

Assume `avcl` is a pointer of empty interface, `level` is integer and `fmt` is string, we can try to replace the varargs in C function with a slice of interfaces (`...interface{}`) in Go function:

go

import "fmt"

func av_log(avcl *interface{}, level int, format string, v ...interface{}) {
    av_vlog(avcl, level, format, v...)
}

func av_vlog(avcl *interface{}, level int, fmt string, v ...interface{}) {
    //Equivalent piece of code
    fmt.Printf(fmt, v...)
}

Above `av_log` function mimics the similar function signature. Function `av_vlog` method would be needed in context as per requirement in left as comment for hint. 

Keep in mind, to call this function, `av_vlog`'s definition is needed and arguments need to be of / implement the necessary interface.

Here's an example of how it can be used:

go
av_log(nil, 5, "example log %v %v", 123, "abc")

This would print : "example log 123 abc" 

Input `fmt` string("example log %v %v") along with replacements(as 123, "abc") come under type `...interface{}` in context of Go. And the function signature working would depend upon the types accepted for these argument slices(`...interface{}`). Example provided substitutes "%v" flags in `fmt` fmt with `123` and `"abc"` respectively. 

More suitable base code would particularize 'avcl','level' variables usage and implant string formatting conversion formatting according to C usage/need.