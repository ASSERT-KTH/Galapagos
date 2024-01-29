Unfortunately, Go does not support function pointers exactly the way they are used in your C code.

However, let's assume that there is some handling procedure we need to call, which can also be nil (you explain `_misuse_handler`). 

We can use a function variable and function types to do something similar to this in Go.
Given that `SodiumCritEnter` and `SodiumCritLeave` are function declarations returning a boolean, `misuseHandler` is a variable of function type with a "(void)" kind of definition.

Usage in go looks something like this,
go
package main

var misuseHandler func()
var sodiumCritEnter func() bool
var sodiumCritLeave func() bool

func sodiumMisuse() {
    sodiumCritLeave()
    if sodiumCritEnter() {
        if misuseHandler != nil {
            misuseHandler()
        }
    }
    panic("abort")    //In go, abort call can be achieved by panic and recover mechanism
}
