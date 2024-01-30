It is possible to crate a similar function as the provided C function code using Go. Note that Go's standard library does not provide direct analogous to zeros a memory block represented by void pointer like memset() in C. That said, it's worth noting that new variables (including those representing slices or arrays) start with zero value in Go, including initializing arrays with zeros so the use of memset() is less frequent in Go.

Here is a possible Go implementation:
from 'bytes' and 'errors' packages:

go
package main

import (
	"bytes"
	"errors"
)

var errNotAbleToAllocateMemory = errors.New("not able to allocate memory")

func sodiumMalloc(size int) ([]byte, error) {
	ptr := make([]byte, size)
	if ptr == nil {
		return nil, errNotAbleToAllocateMemory
	}

	// Fill ptr with 0 (Go doesn't support direct fill like C memset)
	bytes.Repeat([]byte{'0'}, size)

	return ptr, nil
}

Here, we are mimicking the behavior of sodium_malloc() by creating a byte slice of the desired size using Go's built-in make() function, and then filling this slice with zeros using 'bytes' package function - Repeat(). If make() is not able to allocate the desired amount of memory, it returns an error. Please replace '0' byte with your appropriate value for GARBAGE_VALUE just like original C code for the equivalent action.