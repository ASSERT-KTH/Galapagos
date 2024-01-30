As Go doesn't have built-in support for big numbers and memory pointers like C does, your question poses a bit of a challenge. The rough equivalent conceptually could look something like the following code snippet, relying on Go's big package for handling big numbers, and taking into consideration that the garbage collector in Go automatically handles deallocation of variables. Also please note that error handling is not direct analog in Go.

go
import (
    "math/big"
)

func BNFree(a *big.Int) {
    if a == nil {
        return
    }
    //openSSL logic is hidden in this code as Go doesn't support it and detailed errors.
    a = new(big.Int) 	// Assigning a new memory location effectively discarding the old value and making it 
                        // eligible for garbage collection
}


Remember that you can't rewrite this exact function in Go as it implies low level manipulations which Go usually abstracts away (e.g., openssl_free versus garbage collection). Moreover the FLAGS in BigNum are low level operations often related to memory management or the implementations detail which Go has a different approach for.
So, take this as a possible direction to the "similar idea conversion" from C-OpenSSL to Go but not a straight copy-paste as it doesn't fit conceptually in Go's philosophy (forcing manual memory management and C internals implementations like openssl flags into Go).

It's highly suggested to nitpick wisely when switching from a low-level language to a higher-level language. Each language is designed to handle particular restrictions hence, the solutions previously used in one, might not make sense (are not necessary or cannot be compiled) in the other one. 

In other words, Go does things in a different way and it will not usually allow messing up with things C does. Therefore, one must encapsulate C low-level codes in appropriate Go constructs for smooth Transitions. One must understand OpenSSL and Go equivalency comprehensively while Translating.