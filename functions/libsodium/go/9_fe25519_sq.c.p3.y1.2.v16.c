go
func fe25519Sq(h []int32, f []int32) {
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

    f0_2 := 2 * f0
    f1_2 := 2 * f1
    f2_2 := 2 * f2
    f3_2 := 2 * f3
    f4_2 := 2 * f4
    f5_2 := 2 * f5
    f6_2 := 2 * f6
    f7_2 := 2 * f7
    f5_38 := 38 * f5 // 1.959375*2^30
    f6_19 := 19 * f6 // 1.959375*2^30
    f7_38 := 38 * f7 // 1.959375*2^30
    f8_19 := 19 * f8 // 1.959375*2^30
    f9_38 := 38 * f9 // 1.959375*2^30

    f0f0   := int64(f0) * int64(f0)
    f0f1_2 := int64(f0_2) * int64(f1)
    f0f2_2 := int64(f0_2) * int64(f2)
    f0f3_2 := int64(f0_2) * int64(f3)
    f0f4_2 := int64(f0_2) * int64(f4)
    f0f5_2 := int64(f0_2) * int64(f5)
    f0f6_2 := int64(f0_2) * int64(f6)
    f0f7_2 := int64(f0_2) * int64(f7)
    f0f8_2 := int64(f0_2) * int64(f8)
    f0f9_2 := int64(f0_2) * int64(f9)
    f1f1_2 := int64(f1_2) * int64(f1)
    f1f2_2 := int64(f1_2) * int64(f2)
    f1f3_4 := int64(f1_2) * int64(f3_2)
    f1f4_2 := int64(f1_2) * int64(f4)
    f1f5_4 := int64(f1_2) * int64(f5_2)
    f1f6_2 := int64(f1_2) * int64(f6)
    f1f7_4 := int64(f1_2) * int64(f7_2)
    f1f8_2 := int64(f1_2) * int64(f8)
    f1f9_76 := int64(f1_2) * int64(f9_38)
    f2f2 := int64(f2) * int64(f2)
    f2f3_2 := int64(f2_2) * int64(f3)

    [... your variables must continue here...]

    h0 := f0f0 + f1f9_76 + f2f8_38 + f3f7_76 + f4f6_38 + f5f5_38
    h1 := f0f1_2 + f2f9_38 + f3f8_38 + f4f7_38 + f5f6_38
    h2 := f0f2_2 + f1f1_2 + f3f9_76 + f4f8_38 + f5f7_76 + f6f6_19
    h3 := f0f3_2 + f1f2_2 + f4f9_38 + f5f8_38 + f6f7_38
    h4 := f0f4_2 + f1f3_4 + f2f2 + f5f9_76 + f6f8_38 + f7f7_38
    h5 := f0f5_2 + f1f4_2 + f2f3_2 + f6f9_38 + f7f8_38
    h6 := f0f6_2 + f1f5_4 + f2f4_2 + f3f3_2 + f7f9_76 + f8f8_19
    h7 := f0f7_2 + f1f6_2 + f2f5_2 + f3f4_2 + f8f9_38
    h8 := f0f8_2 + f1f7_4 + f2f6_2 + f3f5_4 + f4f4 + f9f9_38
    h9 := f0f9_2 + f1f8_2 + f2f7_2 + f3f6_2 + f4f5_2

    var carry0,carry1,carry2,carry3,carry4,carry5,carry6,carry7,carry8,carry9 int64

    carry0 = (h0 + int64(1<<25)) >> 26
    h1 += int64(carry0)
    h0 -= carry0 * int64((1<<26))
    carry4 = (h4 + int64(1<<25)) >> 26
    h5 += int64(carry4)
    h4 -= carry4 * int64((1<<26))

    carry1 = (h1 + int64(1<<24)) >> 25
			[... carry on your code here...]

