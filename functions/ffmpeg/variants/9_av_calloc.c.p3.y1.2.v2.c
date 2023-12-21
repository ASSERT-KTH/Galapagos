The original function in the above code appears to be part of a custom library (found in FFmpeg sources as per these related examples) which won't be available in Go; there's no `av_mallocz` function in standard Go library. It also uses a custom function `size_mult` for overflow-safe multiplication which is also not trivially available in Go. However we can give a function which has comparable operation.

The closest equivalent, handling the principle behind this function (a check safe multiplication before the allocation and zero initialization), can be as follows:

go
func avCalloc(nmemb int, size int) []byte {
    result := big.NewInt(0).Mul(big.NewInt(int64(nmemb)), big.NewInt(int64(size)))
    if result.IsInt64() && result.Int64() > 0 && result.Int64() < math.MaxInt64 {
        return make([]byte, result.Int64())
    }
    return nil
}


The Go function 'avCalloc' will perform a multiplication that accounts for potential integer overflow situations by using big integer arithmetic. If the result overflows int64, the allocation is inhibited and explicitly returns a nil slice. 

Where zero initialization is implicit when using `make([]byte, n)`, slicing from a big endian representation would only have leading 0's skipped which does not change the integer value. 

This does not precisely comply with the C signature, but in Go, handling a function which operates on an unknown type isn't possible the same way it is in C (you would have to use either reflection or interfaces.), and `void *` roughly corresponds to Go's `interface{}`, not slice types.