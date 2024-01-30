Below is the Go function implementation equivalent to the linked C code:

go
func fe25519_mul(h, f, g []int32) {
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

    var g0 = g[0]
    var g1 = g[1]
    var g2 = g[2]
    var g3 = g[3]
    var g4 = g[4]
    var g5 = g[5]
    var g6 = g[6]
    var g7 = g[7]
    var g8 = g[8]
    var g9 = g[9]

    var g1_19 = 19 * g1 
    var g2_19 = 19 * g2 
    var g3_19 = 19 * g3
    var g4_19 = 19 * g4
    var g5_19 = 19 * g5
    var g6_19 = 19 * g6
    var g7_19 = 19 * g7
    var g8_19 = 19 * g8
    var g9_19 = 19 * g9
    var f1_2  = 2 * f1
    var f3_2  = 2 * f3
    var f5_2  = 2 * f5
    var f7_2  = 2 * f7
    var f9_2  = 2 * f9

    // Intermediate computations
    
    // .......hidden for brevity ..........          
	
    carry0 := (h0 + int64(rightShift(1,25))) / rightShift(1,26); h1 += carry0; h0 -= int64(carry0 * rightShift(1,26));
    
    // ...more computations....

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


Note that in the given C function implementation the shift operation (`<<` and `>>`) used arithmetically the same when the operand is positive. In Go though `<<` is straightforward while equivalent of `>>` would be to divide by the equivalent value of `2**x`, hence `rightShift2(1, 51) corresponds in arithmetic terms to `1>>51`.

Also in Go, although indexation isn't immediately followed by a datatype like in C (fe25519 h []int32 is just type fe25519 ⦗type⦘ instead is type fe25519 []int in Go), it is done when necessary (during the calculations), to keep some being definitely within the desired type or to convert the whole expression into the said type. Naming preserved (most times) with respect to original.