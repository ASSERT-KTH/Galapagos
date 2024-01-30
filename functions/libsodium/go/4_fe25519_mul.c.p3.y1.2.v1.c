func fe25519_mul(h, f, g [5]uint64) [5]uint64 {
    mask := uint64(0x7ffffffffffff)
    var r0, r1, r2, r3, r4 uint128
    var f0, f1, f2, f3, f4 uint128
    var g0, g1, g2, g3, g4 uint128
    var p [5]uint64
    var carry uint64
    res := [5]uint64{}

    f0 = uint128(f[0])
    f1 = uint128(f[1])
    f2 = uint128(f[2])
    f3 = uint128(f[3])
    f4 = uint128(f[4])

    g0 = uint128(g[0])
    g1 = uint128(g[1])
    g2 = uint128(g[2])
    g3 = uint128(g[3])
    g4 = uint128(g[4])

    f1_19 := 19 * f1
    f2_19 := 19 * f2
    f3_19 := 19 * f3
    f4_19 := 19 * f4

    r0 = f0*g0 + g4*f1_19 + g2*f3_19 + g1*f4_19 + g3*f2_19
    r1 = f0*g1 + f1*g0 + g4*f2_19 + g3*f3_19 + g2*f4_19
    r2 = f0*g2 + f1*g1 + f2*g0 + g4*f3_19 + g3*f4_19
    r3 = f0*g3 + f1*g2 + f2*g1 + f3*g0 + g4*f4_19
    r4 = f0*g4 + f1*g3 + f2*g2 + f3*g1 + f4*g0

    r := [5]uint128{r0, r1, r2, r3, r4}

    for i := 0; i <= 4; i++ {
        p[i] = uint64(r[i] & uint128(mask))
        carry = uint64(r[i] >> 51)
        up := i + 1
        if up > 4 {
            up = 0
            p[0] += carry * 19
        } else {
            r[up] += uint128(carry)
        }
    }

    for i := 0; i <= 4; i++ {
        res[i] = uint64(p[i])
    }

    return res
}