Your request requires transforming a function in C which relies heavily on manual memory deallocation to Go. The Go programming language, however, employs automatic garbage collection and does not expose or allow manual memory deallocation like C's `free` function or similar.

Your C code is also dealing with pointer to a union inside a struct which isn't directly possible with Go as Go does not support unions but we can leverage interface{} to work around that. Here's a rough equivalent implementation in Go, all other factors being equal like converting mpz_clear() semantics somehow, and defining Value and Type types:

go
func freev(v *Value) {
    switch v.u.(type) {
    case string:
        // no operation needed as string will be picked 
        // up by garbage collector
    case *big.Int:
        // clear by setting bits to 0
        v.u.(*big.Int).SetInt64(0)
    default:
        // unknown type nothing to do
    }
    // struct v itself will also be garbage collected
    v = nil
}


Remember, `freev` is not needed in Go programming language actually because Go runtime's garbage collector automatically manages memory. Attempting to apply explicitly memory management common in C actually works against Go's design and advantages. Nonetheless, resources other than memory(i.e, File, DB Connection etc) if any, do have to be managed manually yet.