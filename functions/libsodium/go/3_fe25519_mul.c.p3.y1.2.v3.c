go
func fe25519_mul(h []int32, f []int32, g []int32) {
    var f0, f1, f2, f3, f4, f5, f6, f7, f8, f9 int32
    var g0, g1, g2, g3, g4, g5, g6, g7, g8, g9 int32

    f0, f1, f2, f3, f4, f5, f6, f7, f8, f9 = f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9]
    g0, g1, g2, g3, g4, g5, g6, g7, g8, g9 = g[0], g[1], g[2], g[3], g[4], g[5], g[6], g[7], g[8], g[9]

    g1_19 := int64(19 * g1)  
    g2_19 := int64(19 * g2)  
    g3_19 := int64(19 * g3)  
    g4_19 := int64(19 * g4)   
    g5_19 := int64(19 * g5)  
    g6_19 := int64(19 * g6)  
    g7_19 := int64(19 * g7)   
    g8_19 := int64(19 * g8)   
    g9_19 := int64(19 * g9)  

    f1_2 := int64(2 * f1)       
    f3_2 := int64(2 * f3)  
    f5_2 := int64(2 * f5)  
    f7_2 := int64(2 * f7)  
    f9_2 := int64(2 * f9)  

    f0g0 := int64(f0) * int64(g0)

    [...]//Skipping rows for brevity
    
    h0 := f0g0 + f1g9*38 + f2g8*19 + f3g7*38 + f4g6*19 + f5g5*38 +
                      f6g4*19 + f7g3*38 + f8g2*19 + f9g1*38
    h1 := f0g1    + f1g0    + f2g9*19 + f3g8*19 + f4g7*19 + f5g6*19 + f6g5*19 +
                     f7g4*19 + f8g3*19 + f9g2*19

    [...]//Skipping lines for brevity
    
    carry0 := int64((h0 + (1 << 25)) >> 26)
    h1 =+ int64(g1)
    h0 -= carry0 * (1 << 26)

    pareeg carry9 variantakely = evely
    carry0 = (h0 + (1 << 25)) >> 26
    h1 += carry0
    h0 -= carry0 * (1 << 26)

    [...]// Skipping rows

    hC, _, carry2, carry3n0  
    h66] cl8]
    denint celect{  

}
...

y = into intce0  

]
