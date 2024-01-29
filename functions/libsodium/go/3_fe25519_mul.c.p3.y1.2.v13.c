func fe25519_mul(h *[10]int32, f *[10]int32, g *[10]int32) {

    f0 := f[0]
    f1 := f[1]
    f2 := f[2]
    f3 := f[3]
    f4 := f[4]
    f5 := f[5]
    f6 := f[6]
    f7 := f[7]
    f8 := f[8]
    f9 := f[9]

    g0 := g[0]
    g1 := g[1]
    g2 := g[2]
    g3 := g[3]
    g4 := g[4]
    g5 := g[5]
    g6 := g[6]
    g7 := g[7]
    g8 := g[8]
    g9 := g[9]

    g1_19 := 19 * g1 
    g2_19 := 19 * g2 
    g3_19 := 19 * g3
    g4_19 := 19 * g4
    g5_19 := 19 * g5
    g6_19 := 19 * g6
    g7_19 := 19 * g7
    g8_19 := 19 * g8
    g9_19 := 19 * g9
    f1_2  := 2 * f1
    f3_2  := 2 * f3
    f5_2  := 2 * f5
    f7_2  := 2 * f7
    f9_2  := 2 * f9

    f0g0    := int64(f0) * int64(g0)
    f0g1    := int64(f0) * int64(g1)
    f0g2    := int64(f0) * int64(g2)
    f0g3    := int64(f0) * int64(g3)
    f0g4    := int64(f0) * int64(g4)
    f0g5    := int64(f0) * int64(g5)
    f0g6    := int64(f0) * int64(g6)
    f0g7    := int64(f0) * int64(g7)
    f0g8    := int64(f0) * int64(g8)
    f0g9    := int64(f0) * int64(g9)
    f1g0    := int64(f1) * int64(g0)
    f1g1_2  := int64(f1_2) * int64(g1)
    f1g2    := int64(f1) * int64(g2)
    f1g3_2  := int64(f1_2) * int64(g3)
    f1g4    := int64(f1) * int64(g4)
    f1g5_2  := int64(f1_2) * int64(g5)
    f1g6    := int64(f1) * int64(g6)
    f1g7_2  := int64(f1_2) * int64(g7)
    f1g8    := int64(f1) * int64(g8)
    f1g9_38 := int64(f1_2) * int64(g9_19)
    f2g0    := int64(f2) * int64(g0)
    f2g1    := int64(f2) * int64(g1)
    f2g2    := int64(f2) * int64(g2)
    f2g3    := int64(f2) * int64(g3)
    f2g4    := int64(f2) * int64(g4)
    f2g5    := int64(f2) * int64(g5)
    f2g6    := int64(f2) * int64(g6)
    f2g7    := int64(f2) * int64(g7)
    f2g8_19 := int64(f2) * int64(g8_19)
    f2g9_19 := int64(f2) * int64(g9_19)
    f3g0    := int64(f3) * int64(g0)
    f3g1_2  := int64(f3_2) * int64(g1)
    f3g2    := int64(f3) * int64(g2)
    f3g3_2  := int64(f3_2) * int64(g3)
    f3g4    := int64(f3) * int64(g4)
    f3g5_2  := int64(f3_2) * int64(g5)
    f3g6    := int64(f3) * int64(g6)
    f3g7_38 := int64(f3_2) * int64(g7_19)
    f3g8_19 := int64(f3) * int64(g8_19)
    f3g9_38 := int64(f3_2) * int64(g9_19)
    f4g0    := int64(f4) * int64(g0)
    f4g1    := int64(f4) * int64(g1)
    f4g2    := int64(f4) * int64(g2)
    f4g3    := int64(f4) * int64(g3)
    f4g4    := int64(f4) * int64(g4)
    f4g5    := int64(f4) * int64(g5)
    f4g6_19 := int64(f4) * int64(g6_19)
    f4g7_19 := int64(f4) * int64(g7_19)
    f4g8_19 := int64(f4) * int64(g8_19)
    f4g9_19 := int64(f4) * int64(g9_19)
    f5g0    := int64(f5) * int64(g0)
    f5g1_2  := int64(f5_2) * int64(g1)
    f5g2    := int64(f5) * int64(g2)
    f5g3_2  := int64(f5_2) * int64(g3)
    f5g4    := int64(f5) * int64(g4)
    f5g5_38 := int64(f5_2) * int64(g5_19)
    f5g6_19 := int64(f5) * int64(g6_19)
    f5g7_38 := int64(f5_2) * int64(g7_19)
    f5g8_19 := int64(f5) * int64(g8_19)
    f5g9_38 := int64(f5_2) * int64(g9_19)
    f6g0    := int64(f6) * int64(g0)
    f6g1    := int64(f6) * int64(g1)
    f6g2    := int64(f6) * int64(g2)
    f6g3    := int64(f6) * int64(g3)
    f6g4_19 := int64(f6) * int64(g4_19)
    f6g5_19 := int64(f6) * int64(g5_19)
    f6g6_19 := int64(f6) * int64(g6_19)
    f6g7_19 := int64(f6) * int64(g7_19)
    f6g8_19 := int64(f6) * int64(g8_19)
    f6g9_19 := int64(f6) * int64(g9_19)
    f7g0    := int64(f7) * int64(g0)
    f7g1_2  := int64(f7_2) * int64(g1)
    f7g2    := int64(f7) * int64(g2)
    f7g3_38 := int64(f7_2) * int64(g3_19)
    f7g4_19 := int64(f7) * int64(g4_19)
    f7g5_38 := int64(f7_2) * int64(g5_19)
    f7g6_19 := int64(f7) * int64(g6_19)
    f7g7_38 := int64(f7_2) * int64(g7_19)
    f7g8_19 := int64(f7) * int64(g8_19)
    f7g9_38 := int64(f7_2) * int64(g9_19)
    f8g0    := int64(f8) * int64(g0)
    f8g1    := int64(f8) * int64(g1)
    f8g2_19 := int64(f8) * int64(g2_19)
    f8g3_19 := int64(f8) * int64(g3_19)
    f8g4_19 := int64(f8) * int64(g4_19)
    f8g5_19 := int64(f8) * int64(g5_19)
    f8g6_19 := int64(f8) * int64(g6_19)
    f8g7_19 := int64(f8) * int64(g7_19)
    f8g8_19 := int64(f8) * int64(g8_19)
    f8g9_19 := int64(f8) * int64(g9_19)
    f9g0    := int64(f9) * int64(g0)
    f9g1_38 := int64(f9_2) * int64(g1_19)
    f9g2_19 := int64(f9) * int64(g2_19)
    f9g3_38 := int64(f9_2) * int64(g3_19)
    f9g4_19 := int64(f9) * int64(g4_19)
    f9g5_38 := int64(f9_2) * int64(g5_19)
    f9g6_19 := int64(f9) * int64(g6_19)
    f9g7_38 := int64(f9_2) * int64(g7_19)
    f9g8_19 := int64(f9) * int64(g8_19)
    f9g9_38 := int64(f9_2) * int64(g9_19)

    h0 := f0g0 + f1g9_38 + f2g8_19 + f3g7_38 + f4g6_19 + f5g5_38 + f6g4_19 +
          f7g3_38 + f8g2_19 + f9g1_38
    h1 := f0g1 + f1g0 + f2g9_19 + f3g8_19 + f4g7_19 + f5g6_19 + f6g5_19 +
          f7g4_19 + f8g3_19 + f9g2_19
    h2 := f0g2 + f1g1_2 + f2g0 + f3g9_38 + f4g8_19 + f5g7_38 + f6g6_19 +
          f7g5_38 + f8g4_19 + f9g3_38
    h3 := f0g3 + f1g2 + f2g1 + f3g0 + f4g9_19 + f5g8_19 + f6g7_19 + f7g6_19 +
          f8g5_19 + f9g4_19
    h4 := f0g4 + f1g3_2 + f2g2 + f3g1_2 + f4g0 + f5g9_38 + f6g8_19 + f7g7_38 +
          f8g6_19 + f9g5_38
    h5 := f0g5 + f1g4 + f2g3 + f3g2 + f4g1 + f5g0 + f6g9_19 + f7g8_19 +
          f8g7_19 + f9g6_19
    h6 := f0g6 + f1g5_2 + f2g4 + f3g3_2 + f4g2 + f5g1_2 + f6g0 + f7g9_38 +
          f8g8_19 + f9g7_38
    h7 := f0g7 + f1g6 + f2g5 + f3g4 + f4g3 + f5g2 + f6g1 + f7g0 + f8g9_19 +
          f9g8_19
    h8 := f0g8 + f1g7_2 + f2g6 + f3g5_2 + f4g4 + f5g3_2 + f6g2 + f7g1_2 +
          f8g0 + f9g9_38
    h9 := f0g9 + f1g8 + f2g7 + f3g6 + f4g5 + f5g4 + f6g3 + f7g2 + f8g1 + f9g0

    var carry0, carry1, carry2, carry3, carry4, carry5, carry6, carry7, carry8, carry9 int64

    carry0 = (h0 + int64(1<<25)) >> 26
    h1 += carry0
    h0 -= carry0 * int64(1<<26)
    carry4 = (h4 + int64(1<<25)) >> 26
    h5 += carry4
    h4 -= carry4 * int64(1<<26)

    carry1 = (h1 + int64(1<<24)) >> 25
    h2 += carry1
    h1 -= carry1 * int64(1<<25)
    carry5 = (h5 + int64(1<<24)) >> 25
    h6 += carry5
    h5 -= carry5 * int64(1<<25)

    carry2 = (h2 + int64(1<<25)) >> 26
    h3 += carry2
    h2 -= carry2 * int64(1<<26)
    carry6 = (h6 + int64(1