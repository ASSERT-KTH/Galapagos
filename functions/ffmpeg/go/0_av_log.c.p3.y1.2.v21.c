In Go language, there is no direct way to accept variable length arguments like the "..." in C. But program can take an argument of the type `interface{}` and reflect package can be used to simulate the similar behavior. But, doing so will lead to change in function signature and will complicate the function usage as user will have to know type of each parameter. But if you are fine with the fact that you will pass arguments to formatter(equivalent of fmt) as a slice of interface{}, below code can be written in Golang:

go
package main

import (
	"log"
	"fmt"
)

func av_log(avcl interface{}, level int, formatter string, v ...interface{}) {
	log.Printf(fmt.Sprintf("%v, %d, "+formatter, avcl, level, v...))
}

This function works pretty similar to original C function, where `interface{}` in av_log functions towards void*, log.Printf corresponds to av_vlog i.e logs in similar formate, assuming av_vlog somewhere logs the data. Also, hopefully fmt in question code is essentially acting as formatter and taking variable length arguments which can be used to form log message which can be related to formatter on Golang side. This function can take variable number of arguments at the end like C variadic functions due to the ...interface{} but arguments lose their original type information unlike C.
Just note that Golang doesn't allow variable length arguments like C, best workaround for variadic arguments is to use slice of interfaces which significantly changes function usage. Note: If arguments are known and for a specific purpose function needs to be written based on some specific number of arguments then, signature can be more specific since good programming practices advice against using arbitrary interfaces.