func fe25519_sq(h, f []int32) {
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

    var f0_2  = 2 * f0
    var f1_2  = 2 * f1
    var f2_2  = 2 * f2
    var f3_2  = 2 * f3
    var f4_2  = 2 * f4
    var f5_2  = 2 * f5
    var f6_2  = 2 * f6
    var f7_2  = 2 * f7
    var f5_38 = 38 * f5 
    var f6_19 = 19 * f6 
    var f7_38 = 38 * f7
    var f8_19 = 19 * f8 
    var f9_38 = 38 * f9 

    var f0f0    = int64(f0) * int64(f0)
    var f0f1_2  = int64(f0_2) * int64(f1)
    var f0f2_2  = int64(f0_2) * int64(f2)
    var f0f3_2  = int64(f0_2) * int64(f3)
    var f0f4_2  = int64(f0_2) * int64(f4)
    var f0f5_2  = int64(f0_2) * int64(f5)
    var f0f6_2  = int64(f0_2) * int64(f6)
    var f0f7_2  = int64(f0_2) * int64(f7)
    var f0f8_2  = int64(f0_2) * int64(f8)
    var f0f9_2  = int64(f0_2) * int64(f9)
    var f1f1_2  = int64(f1_2) * int64(f1)
    var f1f2_2  = int64(f1_2) * int64(f2)
    var f1f3_4  = int64(f1_2) * int64(f3_2)
    var f1f4_2  = int64(f1_2) * int64(f4)
    var f1f5_4  = int64(f1_2) * int64(f5_2)
    var f1f6_2  = int64(f1_2) * int64(f6)
    var f1f7_4  = int64(f1_2) * int64(f7_2)
    var f1f8_2  = int64(f1_2) * int64(f8)
    var f1f9_76 = int64(f1_2) * int64(f9_38)
    var f2f2    = int64(f2) * int64(f2)
    var f2f3_2  = int64(f2_2) * int64(f3)
    var f2f4_2  = int64(f2_2) * int64(f4)
    var f2f5_2  = int64(f2_2) * int64(f5)
    var f2f6_2  = int64(f2_2) * int64(f6)
    var f2f7_2  = int64(f2_2) * int64(f7)
    var f2f8_38 = int64(f2_2) * int64(f8_19)
    var f2f9_38 = int64(f2) * int64(f9_38)
    var f3f3_2  = int64(f3_2) * int64(f3)
    var f3f4_2  = int64(f3_2) * int64(f4)
    var f3f5_4  = int64(f3_2) * int64(f5_2)
    var f3f6_2  = int64(f3_2) * int64(f6)
    var f3f7_76 = int64(f3_2) * int64(f7_38)
    var f3f8_38 = int64(f3_2) * int64(f8_19)
    var f3f9_76 = int64(f3_2) * int64(f9_38)
    var f4f4    = int64(f4) * int64(f4)
    var f4f5_2  = int64(f4_2) * int64(f5)
    var f4f6_38 = int64(f4_2) * int64(f6_19)
    var f4f7_38 = int64(f4) * int64(f7_38)
    var f4f8_38 = int64(f4_2) * int64(f8_19)
    var f4f9_38 = int64(f4) * int64(f9_38)
    var f5f5_38 = int64(f5) * int64(f5_38)
    var f5f6_38 = int64(f5_2) * int64(f6_19)
    var f5f7_76 = int64(f5_2) * int64(f7_38)
    var f5f8_38 = int64(f5_2) * int64(f8_19)
    var f5f9_76 = int64(f5_2) * int64(f9_38)
    var f6f6_19 = int64(f6) * int64(f6_19)
    var f6f7_38 = int64(f6) * int64(f7_38)
    var f6f8_38 = int64(f6_2) * int64(f8_19)
    var f6f9_38 = int64(f6) * int64(f9_38)
    var f7f7_38 = int64(f7) * int64(f7_38)
    var f7f8_38 = int64(f7_2) * int64(f8_19)
    var f7f9_76 = int64(f7_2) * int64(f9_38)
    var f8f8_19 = int64(f8) * int64(f8_19)
    var f8f9_38 = int64(f8) * int64(f9_38)
    var f9f9_38 = int64(f9) * int64(f9_38)

    var h0 = f0f0 + f1f9_76 + f2f8_38 + f3f7_76 + f4f6_38 + f5f5_38
    var h1 = f0f1_2 + f2f9_38 + f3f8_38 + f4f7_38 + f5f6_38
    var h2 = f0f2_2 + f1f1_2 + f3f9_76 + f4f8_38 + f5f7_76 + f6f6_19
    var h3 = f0f3_2 + f1f2_2 + f4f9_38 + f5f8_38 + f6f7_38
    var h4 = f0f4_2 + f1f3_4 + f2f2 + f5f9_76 + f6f8_38 + f7f7_38
    var h5 = f0f5_2 + f1f4_2 + f2f3_2 + f6f9_38 + f7f8_38
    var h6 = f0f6_2 + f1f5_4 + f2f4_2 + f3f3_2 + f7f9_76 + f8f8_19
    var h7 = f0f7_2 + f1f6_2 + f2f5_2 + f3f4_2 + f8f9_38
    var h8 = f0f8_2 + f1f7_4 + f2f6_2 + f3f5_4 + f4f4 + f9f9_38
    var h9 = f0f9_2 + f1f8_2 + f2f7_2 + f3f6_2 + f4f5_2

    var carry0 int64
    var carry1 int64
    var carry2 int64
    var carry3 int64
    var carry4 int64
    var carry5 int64
    var carry6 int64
    var carry7 int64
    var carry8 int64
    var carry9 int64

    carry0 = (h0 + (int64(1) << 25)) >> 26
    h1 += carry0
    h0 -= carry0 * (int64(1) << 26)
    carry4 = (h4 + (int64(1) << 25)) >> 26
    h5 += carry4
    h4 -= carry4 * (int64(1) << 26)

    carry1 = (h1 + (int64(1) << 24)) >> 25
    h2 += carry1
    h1 -= carry1 * (int64(1) << 25)
    carry5 = (h5 + (int64(1) << 24)) >> 25
    h6 += carry5
    h5 -= carry5 * (int64(1) << 25)

    carry2 = (h2 + (int64(1) << 25)) >> 26
    h3 += carry2
    h2 -= carry2 * (int64(1) << 26)
    carry6 = (h6 + (int64(1) << 25)) >> 26
    h7 += carry6
    h6 -= carry6 * (int64(1) << 26)

    carry3 = (h3 + (int64(1) << 24)) >> 25
    h4 += carry3
    h3 -= carry3 * (int64(1) << 25)
    carry7 = (h7 + (int64(1) << 24)) >> 25
    h8 += carry7
    h7 -= carry7 * (int64(1) << 25)

    carry4 = (h4 + (int64(1) << 25)) >> 26
    h5 += carry4
    h4 -= carry4 * (int64(1) << 26)
    carry8 = (h8 + (int64(1) << 25)) >> 26
    h9 += carry8
    h8 -= carry8 * (int64(1) << 26)

    carry9 = (h9 + (int64(1) << 24)) >> 25
    h0 += carry9 * 19
    h9 -= carry9 * (int64(1) << 25)

    carry0 = (h0 + (int64(1) << 25)) >> 26
    h1 += carry0
    h0 -= carry0 * (int64(1) << 26)

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