go
func fe25519_mul(h, f, g *[5]uint64) {
    const mask uint64 = 0x7ffffffffffff

    var f0, f1, f2, f3, f4 float64
    f0 = float64(f[0])
    f1 = float64(f[1])
    f2 = float64(f[2])
    f3 = float64(f[3])
    f4 = float64(f[4])

    var g0, g1, g2, g3, g4 float64
    g0 = float64(g[0])
    g1 = float64(g[1])
    g2 = float64(g[2])
    g3 = float64(g[3])
    g4 = float64(g[4])

    var f1_19, f2_19, f3_19, f4_19 float64
    f1_19 = 19.0 * f1
    f2_19 = 19.0 * f2
    f3_19 = 19.0 * f3
    f4_19 = 19.0 * f4

    var r0, r1, r2, r3, r4 float64
    r0 = f0*g0 + f1_19*g4 + f2_19*g3 + f3_19*g2 + f4_19*g1
    r1 = f0*g1 + f1*g0 + f2_19*g4 + f3_19*g3 + f4_19*g2
    r2 = f0*g2 + f1*g1 + f2*g0 + f3_19*g4 + f4_19*g3
    r3 = f0*g3 + f1*g2 + f2*g1 + f3*g0 + f4_19*g4
    r4 = f0*g4 + f1*g3 + f2*g2 + f3*g1 + f4*g0

    r00 := float64(uint64(r0)) * mask 
    carry := r0 / math.Pow(2, 51)
    r1 += carry
    r01 := uint64(r1) * mask 
    carry = r1 / math.Pow(2, 51)
    r2 += carry
    r02 := uint64(r2) * mask 
    carry = r2 / math.Pow(2, 51)
    r3 += carry
    r03 := uint64(r3) * mask
    carry = r3 / math.Pow(2, 51)
    r4 += carry
    r04 := uint64(r4) * mask
    carry = r4 / math.Pow(2, 51)
    r00 += 19 * carry
    carry = r00 / math.Pow(2, 51)
    r00 *= mask
    r01 += uint64(carry)
    carry = float64(r01) / math.Pow(2, 51)
    r01 *= mask
    r02 += uint64(carry)

    h[0] = uint64(r00)
    h[1] = uint64(r01)
    h[2] = uint64(r02)
    h[3] = uint64(r03)
    h[4] = uint64(r04)
}
