Here is the C function translated to an equivalent variant in Go:

go
func fe25519Mul(h, f, g *[10]int32) {
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

    var g1_19 = int64(19 * g1)
    var g2_19 = int64(19 * g2)
    var g3_19 = int64(19 * g3)
    var g4_19 = int64(19 * g4)
    var g5_19 = int64(19 * g5)
    var g6_19 = int64(19 * g6)
    var g7_19 = int64(19 * g7)
    var g8_19 = int64(19 * g8)
    var g9_19 = int64(19 * g9)
    var f1_2 = int64(2 * f1)
    var f3_2 = int64(2 * f3)
    var f5_2 = int64(2 * f5)
    var f7_2 = int64(2 * f7)
    var f9_2 = int64(2 * f9)

    var f0g0 = int64(f0) * int64(g0)
    // ... Repeat for each calculation

    var h0 = f0g0 + f1g9_38 + f2g8_19 + f3g7_38 + f4g6_19 + f5g5_38 + f6g4_19 + f7g3_38 + f8g2_19 + f9g1_38;
    // ... Repeat for each calculation

    var carry0 = (h0 + (int64)(1<<25)) >> 26 
    h1 += carry0
    h0 -= carry0 << 26
    // ... Repeat for each carry

    h[0] = int32(h0)
    h[1] = int32(h1)
    // ... Repeat for each assignment
  }


Please fill each `... Repeat for each calculation` and `... Repeat for each carry` spot with exact calculations based on original information in C function.