func fe25519_mul(h, f, g *[5]uint64) {
    const mask uint64 = 0x7ffffffffffff
    var r0, r1, r2, r3, r4 uint64
    var f1_19, f2_19, f3_19, f4_19 uint64
    var carry uint64

    f1_19 = 19 * f[1]
    f2_19 = 19 * f[2]
    f3_19 = 19 * f[3]
    f4_19 = 19 * f[4]

    r0 = f[0]*g[0] + f1_19*g[4] + f2_19*g[3] + f3_19*g[2] + f4_19*g[1]
    r1 = f[0]*g[1] + f[1]*g[0] + f2_19*g[4] + f3_19*g[3] + f4_19*g[2]
    r2 = f[0]*g[2] + f[1]*g[1] + f[2]*g[0] + f3_19*g[4] + f4_19*g[3]
    r3 = f[0]*g[3] + f[1]*g[2] + f[2]*g[1] + f[3]*g[0] + f4_19*g[4]
    r4 = f[0]*g[4] + f[1]*g[3] + f[2]*g[2] + f[3]*g[1] + f[4]*g[0]

    r0, carry = bits.Add64(r0, 0, 0)
    r0 &= mask
    r1, carry = bits.Add64(r1, carry, 0)
    r1 &= mask
    r2, carry = bits.Add64(r2, carry, 0)
    r2 &= mask
    r3, carry = bits.Add64(r3, carry, 0)
    r3 &= mask
    r4, carry = bits.Add64(r4, carry, 0)
    r4 &= mask

    r0, carry = bits.Add64(r0, carry*19, 0)
    r0 &= mask
    r1, carry = bits.Add64(r1, carry, 0)
    r1 &= mask
    r2, carry = bits.Add64(r2, carry, 0)
    r2 &= mask

    h[0] = r0
    h[1] = r1
    h[2] = r2
    h[3] = r3
    h[4] = r4
}