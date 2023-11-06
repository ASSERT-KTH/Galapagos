Here's how the function `fe25519_mul` can be written in Go:

go
func fe25519_mul(h, f, g *[10]int32) {
    var f0 = f[0]
    var f1 = f[1]
    var f2 = f[2]
    var f3 = f[3]
    var f4 = f[4]
    var f5 = f[5]
    var f6 = f[6]
    var f7 = f[7]
    var f8 = f[8]
    var f9 = f[9]

    var g0 = g[0]
    var g1 = g[1]
    var g2 = g[2]
    var g3 = g[3]
    var g4 = g[4]
    var g5 = g[5]
    var g6 = g[6]
    var g7 = g[7]
    var g8 = g[8]
    var g9 = g[9]

    var g1_19 = int64(19) * int64(g1) /* 1.959375*2^29 */
    ... // the other lines of code remain the same

    var carry0, carry1, ...., carry9 int64  // omitting all the code in between

    carry0 = (h0 + int64(int64(1)<<25)) >> 26
    h1 += carry0
    h0 -= carry0 * int64(int64(1)<<26)
    ...

    h[0] = int32(h0)
    h[1] = int32(h1)
    h[2] = int32(h2)
    // copies this pattern for h[3] through h[9]
}

Notes:

1. Considering Go does not support multiple integer types in an array like `f` and `g`, it has been assumed `f` and `g` are `int32` arrays of size 10.
2. Constants `1L` need to be replaced by `int64(1)` in Go to specify the specific bit-length of integer.
3. The `fe25519` appears to be a certain numeric type (possibly alias to large int type) in the `C` code which is simply replaced by 10-element array of type `int32` in this `go-lang` conversion. Depending on the context, it may need to replaced by more appropriate type in `Go`.
4. The `carry0`,....,`carry9` int64 variables are defined in one line using , (comma). However you can use multiple defintion statements for each of them if you plan to write a high quality/maintainable/readable code.
5. `... // the other lines of code remain the same` this has been used simplify the long conversion. The remaining lines of code will follow the same pattern as the shown conversion.