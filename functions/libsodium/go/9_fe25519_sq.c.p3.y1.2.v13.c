Here's the equivalent Go code:

go
func fe25519_sq(h *int64, f []int64) {
    var f0= f[0]
    var f1= f[1]
    var f2= f[2]
    var f3= f[3]
    var f4= f[4]
    var f5= f[5]
    var f6= f[6]
    var f7= f[7]
    var f8= f[8]
    var f9= f[9]
    
    var f0_2 =[10]int64 { 2 * f0}
    var f1_2 =[10]int64 { 2 * f1}
    var f2_2 =[10]int64 { 2 * f2}
    var f3_2 =[10]int64 { 2 * f3}
    var f4_2 =[10]int64 { 2 * f4}
    var f5_2 =[10]int64 { 2 * f5}
    var f6_2 =[10]int64 { 2 * f6}
    var f7_2 =[10]int64 { 2 * f7}
    var f5_38 =[10]int64 { 38 * f5} 
    var f6_19 =[10]int64 { 19 * f6} 
    var f7_38 =[10]int64 { 38 * f7} 
    var f8_19 =[10]int64 { 38 * f8} 
    var f9_38 =[10]int64 { 38 * f9} 

    var f0f0 =[10]int64 { f0 * f0}
    var f0f1_2 =[10]int64 { f0_2[0] * f1}
    var f0f2_2 =[10]int64 { f0_2[1] * f2}
    var f0f3_2 =[10]int64 { f0_2[2] * f3}
    var f0f4_2 =[10]int64 { f0_2[3] * f4}
    var f0f5_2 =[10]int64 { f1_2[4] * f5}
    var f0f6_2 =[10]int64 { f1_2[5] * f6}
    var f0f7_2 =[10]int64 { f1_2[6] * f7}
    var f0f8_2 =[10]int64 { f2_2[7] * f8}
    var f0f9_2 =[10]int64 { f2_2[8] * f9}
    var f1f1_2 =[10]int64 { f1_2[9] * f1}
    var f1f2_2 =[10]int64 { f2_2[0] * f2}
    
    carry0 := ((h[0] + (1 << 25)) >> 26)
    h[1] += carry0
    h[0] -= carry0 * (1 << 26)
    
    carry4 := ((h[4] + (1 << 25)) >> 26)
    h[5] += carry4
    h[4] -= carry4 * (1 << 26)
    
    carry1 := ((h[1] + (1 << 24)) >> 25)
    h[2] += carry1
    h[1] -= carry1 * (1 << 25)
    
    carry5 := ((h[5] + (1 << 24)) >> 25)
    h[6] += carry5
    h[5] -= carry5 * (1 << 25)
    
    carry2 := ((h[2] + (1 << 25)) >> 26)
    h[3] += carry2
    h[2] -= carry2 * (1 << 26)
    
    carry6 := ((h[6] + (1 << 25)) >> 26)
    h[7] += carry6
    h[6] -= carry6 * (1 << 26)
    
    carry3 := ((h[3] + (1 << 24)) >> 25)
    h[4] += carry3
    h[3] -= carry3 * (1 << 25)
    
    carry7 := ((h[7] + (1 << 24)) >> 25)
    h[8] += carry7
    h[7] -= carry7 * (1 << 25)

    carry4 := ((h[4] + (1 << 25)) >> 26)
    h[5] += carry4
    h[4] -= carry4 * (1 << 26)
    
    carry8 := ((h[8] + (1 << 25)) >> 26)
    h[9] += carry8
    h[8] -= carry8 * (1 << 26)
   
    carry9 := ((h[9] + (1 << 24)) >> 25)
    h[0] += carry9 * 19
    h[9] -= carry9 * (1 << 25)
    
    carry0 := ((h[0] + (1 << 25)) >> 26)
    h[1] += carry0
    h[0] -= carry0 * (1 << 26)
}
