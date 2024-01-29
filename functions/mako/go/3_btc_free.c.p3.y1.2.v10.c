In Go programming language, you don't need to explicitly free allocated memory, as this is handled by garbage collector. Therefore, checking for nil isn't needed either.

In terms of behavior though, a semantically equivalent in Go can contain an if statement checking for nil and causing a panic, which is the closest equivalent to C's abort().

package main

import (
	"fmt"
)

func btc_free(ptr *interface{}) {
	if ptr == nil {
		panic("Cannot free null pointer!")
	}
}

Note: Following Go's conventions, actually dereferencing the pointer or forcing garbage collection are both not recommended and those tasks should be left up to the runtime.