In Go, variables are allocated and deallocate automatically unlike in C where you need to manually manage memory. But you can provide a way to clean up resources using a method. Assuming that `VALUE` is struct with fields 'type' which could be of custom enum type (string or integer like below) and 'u' another struct with fields s (for string) and i (for Int big type). A semantically equivalent version of the function in Go would be:

go
package main

import "math/big"

type Type int

const (
	string_val Type = iota
	integer_val   
)

type Union struct {
    s string
    i *big.Int
}

type VALUE struct {
    dataType Type
    u Union
}

func (v *VALUE) freev() {
    if v.dataType == string_val {
        v.u.s = ""
    } else if v.dataType == integer_val {
        v.u.i = new(big.Int)
    }
}


Note: 'freev' requires a pointer receiver ('*VALUE') to allow it to modify the struct. 
In Go we do not explicitly deallocate memory like the 'free' function in C. Garbage collector manages memory automatically. For the 'mpz_clear' function used for liberating the space occupied by a integer in GMP library in C, in Go, we are just assigning a new `big.Int`