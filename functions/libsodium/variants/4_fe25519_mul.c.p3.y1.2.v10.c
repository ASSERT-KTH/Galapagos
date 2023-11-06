Here's the equivalent Go Function:

go
func fe25519_mul(h, f, g [5]uint64) {

    const mask uint64 = (1 << 51)-1
    var r0, r1, r2, r3, r4 uint64 
    var f0, f1, f2, f3, f4 uint64 
    var f1_19, f2_19, f3_19, f4_19 uint64 
    var g0, g1, g2, g3, g4 uint64 
    var carry uint64 

    f0 = f[0]
    f1 = f[1]
    f2 = f[2]
    f3 = f[3]
    f4 = f[4]

    g0 = g[0]
    g1 = g[1]
    g2 = g[2]
    g3 = g[3]
    g4 = g[4]

    f1_19 = 19 * f1
    f2_19 = 19 * f2
    f3_19 = 19 * f3
    f4_19 = 19 * f4

    r0 = f0*g0 + f1_19*g4 + f2_19*g3 + f3_19*g2 + f4_19*g1
    r1 = f0*g1 + f1*g0     + f2_19*g4 + f3_19*g3 + f4_19*g2
    r2 = f0*g2 + f1*g1     + f2*g0     + f3_19*g4 + f4_19*g3
    r3 = f0*g3 + f1*g2     + f2*g1     + f3*g0     + f4_19*g4
    r4 = f0*g4 + f1*g3     + f2*g2     + f3*g1     + f4*g0
  
    carry = r0 >> 51 
    r0 = r0 & mask
    r1 += carry
    
    carry = r1 >> 51 
    r1 = r1 & mask
    r2 += carry
    
    carry = r2 >> 51 
    r2 = r2 & mask
    r3 += carry

    carry = r3 >> 51 
    r3 = r3 & mask
    r4 += carry
    
    carry = r4 >> 51 
    r4 = r4 & mask
    r0 += carry * 19

    h[0] = r0
    h[1] = r1
    h[2] = r2
    h[3] = r3
    h[4] = r4
    return
}

This function take three arguments of type [5]uint64 which are slices of 5 uint64 numbers, and modify the first one inplace. The logic implemented is exactly the same as the one in the C version.