Since Go is a garbage collected language, it does not need a direct equivalent to "sodium_free" function. In most cases, developers don't need to explicitly release memory in Go, they can just let the unused memory be garbage collected. However if a semantically equivalent version is required to be done, you must use the "unsafe" package the "C" package in Go to interact with pointers, raw memory, call C functions, etc. which is not considered idiomatic and is rarely done in Go.

As the Go doesn't support pointer arithmetic or any way to manipulate memory directly at certain address, It's not directly possible to implement this function exactly the same. Adding or subtracting from a pointer, directly accessing memory by addressing isn't allowed understandably because it ends up defeating a purpose of a garbage collection and automatic memory management. 

Below is a snippet that shows you how you can use C code within Go. This involves using CGo, a feature which allows you to call C-code from within your Go application: 

Go
/*
#cgo CFLAGS: -I .
#cgo LDFLAGS: -lssl -lcrypto
#include <sodium.h>

void call_sodium_free(unsigned char * ct){
    sodium_free(ct);
}
*/
import "C"

import "unsafe"

func SodiumFree(ct []byte) {
    pointer := unsafe.Pointer(&ct[0])
    C.call_sodium_free((*C.uchar)(pointer))
}
