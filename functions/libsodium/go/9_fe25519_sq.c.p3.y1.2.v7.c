go
func fe25519_sq(h *[10]int32, f *[10]int32) {
    var f0 int32 = f[0]
    var f1 int32 = f[1]
    var f2 int32 = f[2]
    var f3 int32 = f[3]
    var f4 int32 = f[4]
    var f5 int32 = f[5]
    var f6 int32 = f[6]
    var f7 int32 = f[7]
    var f8 int32 = f[8]
    var f9 int32 = f[9]

    var f0_2 int64 = 2 * int64(f0)
    var f1_2 int64 = 2 * int64(f1)
    var f2_2 int64 = 2 * int64(f2)
    var f3_2 int64 = 2 * int64(f3)
    var f4_2 int64 = 2 * int64(f4)
    var f5_2 int64 = 2 * int64(f5)
    var f6_2 int64 = 2 * int64(f6)
    var f7_2 int64 = 2 * int64(f7)
    var f5_38 int64 = 38 * int64(f5)
    var f6_19 int64 = 19 * int64(f6)
    var f7_38 int64 = 38 * int64(f7)
    var f8_19 int64 = 19 * int64(f8)
    var f9_38 int64 = 38 * int64(f9)

    var f0f0 = f0 * int64(f0)
    var f0f1_2 = f0_2 * int64(f1)
    var f0f2_2 = f0_2 * int64(f2)
    var f0f3_2 = f0_2 * int64(f3)
    var f0f4_2 = f0_2 * int64(f4)
    var f0f5_2 = f0_2 * int64(f5)
    var f0f6_2 = f0_2 * int64(f6)
    var f0f7_2 = f0_2 * int64(f7)
    var f0f8_2 = f0_2 * int64(f8)
    var f0f9_2 = f0_2 * int64(f9)
    
    //...
 

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
