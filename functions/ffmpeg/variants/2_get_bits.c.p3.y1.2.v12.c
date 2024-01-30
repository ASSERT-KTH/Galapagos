Since the provided C code depends on various macros such as `OPEN_READER`, `UPDATE_CACHE`, and etc, couldn't be just directly ported to Go because Go doesn't support macros like C does. If the macro knowledge were provided, it'll be relatively translational, assuming that types and data structures needed have similar behavior or representation, which are required for this code to work, so it's not actually possible to provide completely equivalent Go code without them.

I present a hypothetical code to represent semantic and syntactic equivalence to the C code "as much as possible". Following a hypothetical nature, assertions and macros details have been replaced by placeholders and possibly incorrect basic example logic because it purely depends on the context and beyond.

go
package main

type GetBitContext struct {
   // define the struct elements based on your application.
} 

func getBits(s *GetBitContext, n int) uint32 {
    var tmp uint32

    // OPEN_READER(re, s)
    // Addition logic to replace C macro.

    //av_assert2(n>0 && n<=25)
    // Replace av_assert2 with standard library methods.
    if !(n > 0 && n <= 25) {
        panic("n is outside the allowed range ")
    }

    // UPDATE_CACHE(re, s)
    // Addition logic to replace C macro.
    
    // tmp = SHOW_UBITS(re, s, n)
    //Additional logic to compute value of tmp , showcase of BITS.

    // LAST_SKIP_BITS(re, s, n)
    // additional logic to equivalent bahaviour as LAST_SKIP_BITS

    // av_assert2(tmp < UINT64_C(1) << n)
    // Replace av_assert2 with standard library methods.
    if !(tmp < 1<<n) {
        panic("tmp is greater than the allowed limit")
    }
    return tmp
}

Please note, THIS IS NOT CONSIDER COMPLETE go version of provided C code, As without those define macro and GetBitContext.

Also it is important to note that Go also does not have `inline` functions. All functions in Go are basically hoisted at package-level, acting standalone. The purpose of an `inline` function in C is to insert code at the call site directly to eliminate the call overhead and optimize further, is automatically used the Go compiler makes a decision of inlining compiled byte-code.