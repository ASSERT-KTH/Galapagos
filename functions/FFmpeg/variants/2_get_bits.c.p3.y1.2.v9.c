In the Go language, we would not use the register keyword and some other macros that are available in C. But, here is a pretty close transformation of your C code to Go:

go
func getBits(s *GetBitContext, n int) uint {
    var tmp uint
    re := openReader(s)
    if n <= 0 || n > 25 {
        panic("Assertion Failed: n > 0 and n <= 25")
    }
    tmp = appendBits(&re, s, uint(n))
    skipBits(&re, s, uint(n))
    closeReader(&re, s)
    if tmp >= 1 << uint(n) {
        panic("Assertion Failed: tmp < 1 << n")
    }
    return tmp
}
 

This Go code should function somewhat equivalently to your C code, assuming 'UpdateCache, ShowUbits, LastSkipBits, CLOSE_READER' and so on are replaced with Go equivalents implementation. Because these are native C paradigm and implementation specific. Obviously the details of the bit manipulation functions omitted (like 'openReader', 'appendBits', 'skipBits' and 'closeReader') would depend on your specific application. Also please be noted the panic in Go is used where the assertions exist in the C code to maintain equivalence. Usually error handling in Go is done in different way.