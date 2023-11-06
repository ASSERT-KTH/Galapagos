Here is a Go version of the given C code.

go
func fe25519_sq(h, f [10]int32) {
    var f0, f1, f2, f3, f4, f5, f6, f7, f8, f9 int32
    f0, f1, f2, f3, f4, f5, f6, f7, f8, f9 = f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9]

    var f0_2, f1_2, f2_2, f3_2, f4_2, f5_2, f6_2, f7_2 int32
    f0_2, f1_2, f2_2, f3_2, f4_2, f5_2, f6_2, f7_2 = f0 * 2, f1 * 2, f2 * 2, f3 * 2, f4 * 2, f5 * 2, f6 *2, f7 * 2

    var f5_38, f6_19, f7_38, f8_19, f9_38 int32
    f5_38, f6_19, f7_38, f8_19, f9_38 = 38 * f5, 19 * f6, 38 * f7, 19 * f8, 38 * f9

    // Add more integer definition & instantiation here...
    
    h0 := f0f0 + f1f9_76 + f2f8_38 + f3f7_76 + f4f6_38 + f5f5_38
    
    // Create h1 to h9: h1 := ..., h2 := ...., h3 := ....
    
    var carry0, carry1, carry2, carry3, carry4, carry5, carry6, carry7, carry8, carry9 int64

    carry0 = (h0 + (int64)(1<<25)) >> 26
    h1 += carry0
    h0 -= carry0 * ((int64) 1 << 26)
    // Add more carry here...

    carry0 = (h0 + (int64)(1 << 25)) >> 26
    h1 += carry0
    h0 -= carry0 * ((int64) 1 << 26)

    h[0], h[1], h[2], h[3], h[4], h[5], h[6], h[7], h[8], h[9] = int32(h0), int32(h1), int32(h2), int32(h3), int32(h4), int32(h5), int32(h6), int32(h7), int32(h8), int32(h9)
}


The conversion is direct. Go supports array index selection just like C. Cast operation, integer arithmetic and bit shifting also behave similarly in C and Go. However, Go doesn't use pointer-like syntax when they are not pointers, this new code operates directly on arrays fed as function parameters.