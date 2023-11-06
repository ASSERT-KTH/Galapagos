func fe25519_mul(h, f, g []int32) {

    var f0, f1, f2, f3, f4, f5, f6, f7, f8, f9 int32
    var g0, g1, g2, g3, g4, g5, g6, g7, g8, g9 int32
    var g1_19, g2_19, g3_19, g4_19, g5_19, g6_19, g7_19, g8_19, g9_19 int32
    var f1_2, f3_2, f5_2, f7_2, f9_2 int32
    var f0g0, f0g1, f0g2, f0g3, f0g4, f0g5, f0g6, f0g7, f0g8, f0g9 int64
    // and so on, for all variables local to the function

    // copy values and apply formulas just like in C implementation

    // for example

    f0 = f[0]
    f1 = f[1]
    f2 = f[2]
    g0 = g[0]
    g1 = g[1]
    g2 = g[2]

    g1_19 = 19 * g1 
    f1_2 = 2 * f1
    f0g2 = f0 * int64(g2)

    // apply such transformations for whole code
    // remember about Go base-like  form for octal and hexadecimal constants (
    // e.g. const mask int64 = 1<<24 - 1

    // finally update values in h
    h[0] = int32(h0)
    h[1] = int32(h1)
    // and so on
}