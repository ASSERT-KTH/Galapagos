Go doesn't have raw pointer operations like C, at least not without using the `unsafe` package, which must be skipped due to best practices. But based on Go's style and garbage collection, here's an example adherent to standard practices:

go
package main

import "unsafe"

func avFreep(arg **interface{}) {
	*arg, *_ = nil, nil
}

func avFree(val interface{}) {
	val = nil
}


Note: You typically don't manually manage memory like this in Go. The garbage collector handles most cases automatically.