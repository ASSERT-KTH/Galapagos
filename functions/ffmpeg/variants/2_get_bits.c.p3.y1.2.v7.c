Unfortunately, there is no direct translation and direct equivalence of your C function in Go. This is mainly because your C function uses several macros such as `OPEN_READER`, `UPDATE_CACHE`, `SHOW_UBITS`, `LAST_SKIP_BITS`, and `CLOSE_READER` that aren't common in C and are not natively existent in Go.

Assuming that the missing parts of the above code snippet manipulate the context of `s`, all of which Go does not allow, it let us also assume that these can be termed into function like behavior. Here is a simple, similar behavior could look like for the `get_bits` computation on Go:

Go
func getBits(s *GetBitContext, n int) uint {
    if n <= 0 || n > 31 {
        panic("n should be range 0 < n <= 31!") // equivalent in Go to av_assert2
    }
    var tmp uint
    s.OpenReader()
    s.UpdateCache()
    tmp = s.ShowUbits(n)
    s.LastSkipBits(n)
    s.CloseReader()
    if tmp >= uint(1) << n {
        panic("tmp is undefined in this scope!")
    }
    return tmp
}
  
Assumptions that are made decoding your c code:

1. `GetBitContext`: contains function like behavior of those several macros of c code.
2. `GetBitContext.OpenReader()`: placeholder for `OPEN_READER` macro
3. `GetBitContext.UpdateCache()`: placeholder for `UPDATE_CACHE` macro
4. `GetBitContext.ShowUbits(n int)`: placeholder for `SHOW_UBITS` macro
5. `GetBitContext.LastSkipBits(n int)`: placeholder for `LAST_SKIP_BITS` macro
6. `GetBitContext.CloseReader()`: placeholder for `CLOSE_READER` macro
7. `n` : In situation of Go context `n` bits must be between 1 and go Uint size which is 32 bits.
8. `uint` vs `unsigned int` : direct equivalent of `C's` `unsigned int` would be go's `uint`.
9. `panic`: An equivalent in Go to `av_assert2` in C is a panic call. Panic stops the execution with appropriate error messages when certain conditions are incorrect.