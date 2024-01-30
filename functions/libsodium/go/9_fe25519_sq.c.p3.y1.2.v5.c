Here is the equivalent Go code:

go
func fe25519Sq(h *[10]int32, f *[10]int32) {
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
    var f5_38 = 38 * f5 // 1.959375*2^30
    var f6_19 = 19 * f6 // 1.959375*2^30

    .
    .
    .
        
    var f9f9_38 = int64(f9) * int64(f9_38)

    var h0 = f0f0 + f1f9_76 + f2f8_38 + f3f7_76 + f4f6_38 + f5f5_38
    // carry continue like this....
        
    .
    .
    .

    h0 -= carry0 * ((1 << 26)) // Here is where difference comes between C and go 
            
    //
    // Similarly modify all other lines like above
    // 
        
    h[9] = int32(h9)
}
 
Therefore, remake the whole function using above guidelines.

In actuality, Go doesn't support implicit type conversion, like may be allowed by C. For an example: 

 var variableName  = variable1 * variable2     // isn't valid in Go when variable1 and variable2 in different types.
 
 Therefore, variables like f5f5_38 need explicit conversion. Fixing this problem by introducing casts to that.