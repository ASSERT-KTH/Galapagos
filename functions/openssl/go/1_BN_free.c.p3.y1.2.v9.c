In Go, there is no direct semantics equivalent for BN_free as Go's garbage collector handles memory management. However, in the context of Big Number (assuming "BIGNUM *a" relates to Big numbers), you may use math/big package in Go. Yet it's almost trivial because the language level disallows the programmer from attempting to free objects' memories manually.

The mathematics/big features work with pointers (*big.Int, for example) so they really share values, yet you can use a fresh one anytime, without thinking about freeing vectors.

In any possible way, setting the pointer to nil implicitly signifies to Go's garbage collector that its memory is free-able when GC runs reluctantly. Yet it is worth stressing that it is unnecessary and that is not an exact translation of your function in C.

If you have a variable of type *big.Int (which we're naming 'a' as a equivalent to BIGNUM), you might explicitly set it to nil like in the example below, which would approximately be a semantic equivalent situation.

go
func BN_free(a *big.Int){
    a = nil
}


Warning again for clarity, this might hint the GC but should not be considered an equivalent of free in go environment. Making something nil in Go does not directly equate to freeing in C. The garbage collector works in the background and the programmer does not explicitly manage memory (this is one of the perks of using Go, less room for manual memory management mistakes).