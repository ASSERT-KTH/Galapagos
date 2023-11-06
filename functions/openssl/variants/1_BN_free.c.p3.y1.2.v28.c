It's almost impossible to keep the function signature `BN_free(BIGNUM *a)` from c into Go. Here's the basic principle though, please modify it based on your actual requirement. 
Following program tries to perform `BN_free` kind of action on `big.Int` but first, remember that Go language is garbage collected, so no equivalent function make much sense in Go as in C. 

go
package main

import (
	"math/big"
	"fmt"
)

type BIGNUM struct {
	b *big.Int
	releaseResources bool
}

func BN_free(a *BIGNUM) {
	if a == nil {
		return
	}
	if a.releaseResources {
		a.b = nil
		fmt.Println("In Go, Framework releases the memory for you. The ref is dropped now and wait for GC.")
	}
}
 

The "mallocced" key matches as closest to `releaseResources` from the struct.