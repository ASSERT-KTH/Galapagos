Go doesn't have an exact equivalent of C's `free` function, because it has a garbage collector that automatically reclaims memory that's no longer used. Go uses interfaces and type assertions for dynamically typed values.

Below is a makeshift adjustment of the original C code to Golang.
Consider the provided struct types are as shown below,

import (
    "math/big"
)

type Valuetype int

const (
    String Valuetype = iota
    Bigint
)

type StringStruct struct {
    s string
}

type BigintStruct struct {
    i *big.Int
}

type VALUE struct {
    typeOf Valuetype
    u      interface{}
}

According to those you can implement the `freev` function as follows,

func freev(v *VALUE) {
    if v.typeOf == String {
        v.u = ""
    } else {
        v.u.(*BigintStruct).i = big.NewInt(0) // Clearing big integer
    }
    // In Go, the GC (Garbage Collection) will eventually clear the memory if no value points to it. 
    // We can set v to nil so the VALUE's memory could be reclaimed as soon as possible. 
  v = nil
}
