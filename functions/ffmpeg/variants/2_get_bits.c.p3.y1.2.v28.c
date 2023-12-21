As in Go there are no macros or inline functions like C. The similar implementation has been done using If conditions, Here is a function Translated into GO:

Note: We don't know the the definition of functions SHOW_UBITS, LAST_SKIP_BITS, CLOSE_READER ...

go
// s & n description is requried as C reference implementation does not provive that
func getBits(s *GetBitContext, n int) uint {
    var tmp uint
    // assuming re is of type some Reader...
    var re Reader
    openReader(&re, s)

    // av_assert2 is a macro that ensure the following condition in C implmentation
    // Go does not support macros -> apply the condition directly 
    if !(n > 0 && n <= 25) {
        panic("av_assert2 failed")
    }
    updateCache(&re, s)
    // next 3 lines include methods not provided in initial C code...
    tmp, err := showUBits(&re, s, &n)
    if err != nil {
        // replace assertion failure with appropriate error handling
    }
    var lastSkip bool
    lastSkip, err := lastSkipBits(&re, s, &n)
    if err != nil {
         // ERROR handling
    } 
    if !lastSkip {
         // may be an ERROR handling or panic with message "LAST_SKIP_BITS FAILURE"
    }
    closeReader(&re, s)
     
    if tmp < 1 << n {
         // ERROR
    }
    return tmp
}


It is to be noted that I couldn't translate C macros to any equivalent Go functionality as C and Go are fundamentally different in that aspect. 
However, updated assertions and function calls according to how you might handle that functionality in Go. Once again, You have to create or improvise the `Reader` type and following function logic according to your need or existing code specification. The provided functions SHOW_UBITS, LAST_SKIP_BITS, CLOSE_READER implementation are required for successful conversion.

`showUBits()`
`lastSkipBits()`
`closeReader()`