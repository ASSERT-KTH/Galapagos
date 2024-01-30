In Go, you are provided with ability to allocate dynamically-sized blocks of memory with the make and new functions. However, note that since it’s Go and safety is one of tight priorities there’s managed memory and you are immediately getting zeroed memory block as opposed to C. However, Go does not support multiplication of size structure with number of elements, so passing these two values separately is redundant. Also, Go supports handling errors better than C, so let's make a slightly more idiomatic Go implementation:

go
package main

import (
    "errors"
)

func avCalloc(count int, elemSize int) ([]byte, error) {

	result := make([]byte, count*elemSize)

	if result == nil {
		return nil, errors.New("Memory allocation failed")
	}

	return result, nil
}


in C, calloc will not fill the memory with zeroes if the size calculation overflows, while that is not really possible in Go, because multiplying two ints that each fit in 31 bits also fit in 63 bits, it can overflow only if you request >2^31-1 items of >1 byte each or >2^30 items of >2 byte each on 32-bit systems, or >2^63-1 or >2^62 on 64-bit systems, which is though technically possible, completely unfeasible practically.