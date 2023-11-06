Unfortunately, some features of the original C code cannot be easily replicated in Go, such as function overloading depending on compiler directives or hardware-dependent functions. Still, a radix simplified version of the original function looks like this in Go.

go
func SodiumMemzero(pnt *[] byte, len int) {
    for i := 0; i < len; i++ {
        pnt[i] = 0
    }
}

The Go's garbage collector handles wiping memory of sensitive data, so a straight-forward memory setting to zero will be optimized and removed in a majority of cases.

Symmetrically mirroring all the feature in the original C code implementation using Go isn’t feasible because Go, unlike C, does not allow for low-level memory manipulation in the same breadth, nor does it support inline assembly or conditional compilation in the same capacity as C.

The function provided above will pass a slice of bytes (this mirrors a void pointer in C) and loop over setting each byte to zero. This loses all the conditional behaviors of the original function, compliant for different operating system’s features & libraries and backward compatibility. 

In essence, while asymmetrically analogous, SodiumMemzero in this Go code should fundamentally execute the same function in practice, given Go’s garbage collector taking care of memory allocation and cleanup. Similarly unfortunate, it would be less performant under certain rare circumstances as the C version.