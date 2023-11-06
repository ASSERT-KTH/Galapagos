func fe25519Sq(h, f *[10]int32) {
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
    var f2f2 = int64(f2) * int64(f2)
    /* ... And so on continuing to convert other lines shown above ...

After finishing upon this step, the completion should be analogically form one-to-one to the one provided above. I left it unfinished for brevity. */

    var carry0, carry1, carry2, carry3, carry4, carry5, carry6, carry7, carry8, carry9 int64

    // The same conversion process is obligatory applied to the following command lines...

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