func fe25519_sq(h []int32, f []int32) {
    f0 := int64(f[0])
    f1 := int64(f[1])
    f2 := int64(f[2])
    f3 := int64(f[3])
    f4 := int64(f[4])
    f5 := int64(f[5])
    f6 := int64(f[6])
    f7 := int64(f[7])
    f8 := int64(f[8])
    f9 := int64(f[9])

    var f0_2  = 2 * f0
    var f1_2  = 2 * f1
    var f2_2  = 2 * f2
    var f3_2  = 2 * f3
    var f4_2  = 2 * f4
    var f5_2  = 2 * f5
    var f6_2  = 2 * f6
    var f7_2  = 2 * f7
    var f5_38 = 38 * f5 // 1.959375*2^30 */
    var f6_19 = 19 * f6 // 1.959375*2^30 */
    var f7_38 = 38 * f7 // 1.959375*2^30 */
    var f8_19 = 19 * f8 // 1.959375*2^30 */
    var f9_38 = 38 * f9 // 1.959375*2^30 */

    var f0f0    = f0 * f0
    var f0f1_2  = f0_2 * f1
    var f0f2_2  = f0_2 * f2
    var f0f3_2  = f0_2 * f3
    var f0f4_2  = f0_2 * f4
    var f0f5_2  = f0_2 * f5
    var f0f6_2  = f0_2 * f6
    var f0f7_2  = f0_2 * f7
    var f0f8_2  = f0_2 * f8
    var f0f9_2  = f0_2 * f9
    var f1f1_2  = f1_2 * f1
    var f1f2_2  = f1_2 * f2
    var f1f3_4  = f1_2 * f3_2
    var f1f4_2  = f1_2 * f4
    var f1f5_4  = f1_2 * f5_2
    var f1f6_2  = f1_2 * f6
    var f1f7_4  = f1_2 * f7_2
    var f1f8_2  = f1_2 * f8
    var f1f9_76 = f1_2 * f9_38
    var f2f2    = f2 * f2
    var f2f3_2  = f2_2 * f3
    var f2f4_2  = f2_2 * f4
    var f2f5_2  = f2_2 * f5
    var f2f6_2  = f2_2 * f6
    var f2f7_2  = f2_2 * f7
    var f2f8_38 = f2_2 * f8_19
    var f2f9_38 = f2 * f9_38
    var f3f3_2  = f3_2 * f3
    var f3f4_2  = f3_2 * f4
    var f3f5_4  = f3_2 * f5_2
    var f3f6_2  = f3_2 * f6
    var f3f7_76 = f3_2 * f7_38
    var f3f8_38 = f3_2 * f8_19
    var f3f9_76 = f3_2 * f9_38
    var f4f4    = f4 * f4
    var f4f5_2  = f4_2 * f5
    var f4f6_38 = f4_2 * f6_19
    var f4f7_38 = f4 * f7_38
    var f4f8_38 = f4_2 * f8_19
    var f4f9_38 = f4 * f9_38
    var f5f5_38 = f5 * f5_38
    var f5f6_38 = f5_2 * f6_19
    var f5f7_76 = f5_2 * f7_38
    var f5f8_38 = f5_2 * f8_19
    var f5f9_76 = f5_2 * f9_38
    var f6f6_19 = f6 * f6_19
    var f6f7_38 = f6 * f7_38
    var f6f8_38 = f6_2 * f8_19
    var f6f9_38 = f6 * f9_38
    var f7f7_38 = f7 * f7_38
    var f7f8_38 = f7_2 * f8_19
    var f7f9_76 = f7_2 * f9_38
    var f8f8_19 = f8 * f8_19
    var f8f9_38 = f8 * f9_38
    var f9f9_38 = f9 * f9_38

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

    var carry0, carry1, carry2, carry3, carry4, carry5, carry6, carry7, carry8, carry9 int64

    carry0 = (h0 + (1<<25)) >> 26
    h[1] += int32(carry0)
    h0 -= carry0 * (1<<26)
    carry4 = (h4 + (1 << 25)) >> 26
    h[5] += int32(carry4)
    h4 -= carry4 * (1 << 26)

    carry1 = (h1 + (1 << 24)) >> 25
    h[2] += int32(carry1)
    h1 -= carry1 * (1 << 25)
    carry5 = (h5 + (1 << 24)) >> 25
    h[6] += int32(carry5)
    h5 -= carry5 * (1 << 25)

    carry2 = (h2 + (1 << 25)) >> 26
    h[3] += int32(carry2)
    h2 -= carry2 * (1 << 26)
    carry6 = (h6 + (1 << 25)) >> 26
    h[7] += int32(carry6)
    h6 -= carry6 * (1 << 26)

    carry3 = (h3 + (1 << 24)) >> 25
    h[4] += int32(carry3)
    h3 -= carry3 * (1 << 25)
    carry7 = (h7 + (1 << 24)) >> 25
    h[8] += int32(carry7)
    h7 -= carry7 * (1 << 25)

    carry4 = (h4 + (1 << 25)) >> 26
    h[5] += int32(carry4)
    h4 -= carry4 * (1 << 26)
    carry8 = (h8 + (1 << 25)) >> 26
    h[9] += int32(carry8)
    h8 -= carry8 * (1 << 26)

    carry9 = (h9 + (1 << 24)) >> 25
    h[0] += int32(carry9 * 19)
    h9 -= carry9 * (1<<25)

    carry0 = (int64(h[0]) + (1<<25)) >> 26
    h[1] += int32(carry0)
    h[0] -= int32(carry0 * (1 << 26))

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