Here is the Go version of the C function:

go
func fe25519_mul(h, f, g [10]int32) {
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

    var g1_19 int32 = 19 * g1 /* 1.959375*2^29 */
    var g2_19 int32 = 19 * g2 /* 1.959375*2^30; still ok */
    var g3_19 int32 = 19 * g3
    var g4_19 int32 = 19 * g4
    var g5_19 int32 = 19 * g5
    var g6_19 int32 = 19 * g6
    var g7_19 int32 = 19 * g7
    var g8_19 int32 = 19 * g8
    var g9_19 int32 = 19 * g9
    var f1_2 int32 = 2 * f1
    var f3_2 int32 = 2 * f3
    var f5_2 int32 = 2 * f5
    var f7_2 int32 = 2 * f7
    var f9_2 int32 = 2 * f9

    var f0g0 int64 = int64(f0) * int64(g0)
    var f0g1 int64 = int64(f0) * int64(g1)
    var f0g2 int64 = int64(f0) * int64(g2)
    var f0g3 int64 = int64(f0) * int64(g3)
    var f0g4 int64 = int64(f0) * int64(g4)
    var f0g5 int64 = int64(f0) * int64(g5)
    var f0g6 int64 = int64(f0) * int64(g6)
    var f0g7 int64 = int64(f0) * int64(g7)
    var f0g8 int64 = int64(f0) * int64(g8)
    var f0g9 int64 = int64(f0) * int64(g9)
    var f1g0 int64 = int64(f1) * int64(g0)
    var f1g1_2 int64 = int64(f1_2) * int64(g1)
    var f1g2 int64 = int64(f1) * int64(g2)
    var f1g3_2 int64 = int64(f1_2) * int64(g3)
    var f1g4 int64 = int64(f1) * int64(g4)
    var f1g5_2 int64 = int64(f1_2) * int64(g5)
    var f1g6 int64 = int64(f1) * int64(g6)
    var f1g7_2 int64 = int64(f1_2) * int64(g7)
    var f1g8 int64 = int64(f1) * int64(g8)
    var f1g9_38 int64 = int64(f1_2) * int64(g9_19)
    // ...Same for all the other fXgY variables...

    var h0 = f0g0 + f1g9_38 + f2g8_19 + f3g7_38 + f4g6_19 + f5g5_38 +
		  f6g4_19 + f7g3_38 + f8g2_19 + f9g1_38
    var h1 = f0g1 + f1g0 + f2g9_19 + f3g8_19 + f4g7_19 + f5g6_19 + f6g5_19 +f7g4_19 + f8g3_19 + f9g2_19
    var h2 = f0g2 + f1g1_2 + f2g0 + f3g9_38 + f4g8_19 + f5g7_38 + f6g6_19 + f7g5_38 + f8g4_19 + f9g3_38
    // ...Same for all the other hX variables...    

    var carry0 = (h0 + (1 << 25)) >> 26
    h1 += carry0
    h0 -= carry0 * (1 << 26)
    var carry4 = (h4 + (1 << 25)) >> 26
    h5 += carry4
    h4 -= carry4 * (1 << 26)
    // ...Same for all the other carryX variables...

    h[0] = int32(h0)
    h[1] = int32(h1)
    h[2] = int32(h2)
    h[3] = int32(h3)
    h[4] = int32(h4)
    h[5] = int32(h5)
    h[6] = int32(h6)
    h[7] = int32(h7)
    h[8] = int32(h8)
    h[9] = int32(h9)
}


Please note that although Go supports int64, it may suit an operation better to use uint64 if the numbers to be calculated don't have the negative domain. Consider to use uint64 type rather than int64 if it fits the sameconditions more often in other operations as well.