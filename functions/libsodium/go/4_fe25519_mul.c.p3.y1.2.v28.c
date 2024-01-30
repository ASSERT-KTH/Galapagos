func fe25519_mul(h []uint64, f []uint64, g []uint64) {
    const mask uint64 = 0x7ffffffffffff
    var r0, r1, r2, r3, r4 uint
    var f0, f1, f2, f3, f4 uint
    var f1_19, f2_19, f3_19, f4_19 uint
    var g0, g1, g2, g3, g4 uint
    var carry uint64

    f0 =  uint(f[0])
    f1 =  uint(f[1])
    f2 =  uint(f[2])
    f3 =  uint(f[3])
    f4 =  uint(f[4])

    g0 =  uint(g[0])
    g1 =  uint(g[1])
    g2 =  uint(g[2])
    g3 =  uint(g[3])
    g4 =  uint(g[4])

    f1_19 = 19 * f1
    f2_19 = 19 * f2
    f3_19 = 19 * f3
    f4_19 = 19 * f4

    r0 = f0*g0 + f1_19*g4 + f2_19*g3 + f3_19*g2 + f4_19*g1
    r1 = f0*g1 + f1*g0 + f2_19*g4 + f3_19*g3 + f4_19*g2
    r2 = f0*g2 + f1*g1 + f2*g0 + f3_19*g4 + f4_19*g3
    r3 = f0*g3 + f1*g2 + f2*g1 + f3*g0 + f4_19*g4
    r4 = f0*g4 + f1*g3 + f2*g2 + f3*g1 + f4*g0

    carry  = uint64(r0 >> 51)
    r1 += carry
    carry  = uint64(r1 >> 51)
    r2 += carry
    carry  = uint64(r2 >> 51)
    r3 += carry
    carry  = uint64(r3 >> 51)
    r4 += carry
    r0 = r0 & mask
    r0 += 19 * uint64(r4 >> 51)
    carry  = r0 >> 51
    r0 = r0 & mask
    r1 += uint(carry)
    carry  = r1 >> 51
    r1 = r1 & mask
    r2 += uint(carry)

    h[0] = uint64(r0)
    h[1] = uint64(r1)
    h[2] = uint64(r2)
    h[3] = uint64(r3)
    h[4] = uint64(r4)
}