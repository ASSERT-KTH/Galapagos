func fe25519_mul(h, f, g *[5]uint64) {
    const mask = 0x7ffffffffffff

    var r0, r1, r2, r3, r4 big.Int
    var f0, f1, f2, f3, f4 big.Int
    var g0, g1, g2, g3, g4 big.Int

    f0.SetInt64(int64(f[0]))
    f1.SetInt64(int64(f[1]))
    f2.SetInt64(int64(f[2]))
    f3.SetInt64(int64(f[3]))
    f4.SetInt64(int64(f[4]))

    g0.SetInt64(int64(f[0]))
    g1.SetInt64(int64(f[1]))
    g2.SetInt64(int64(f[2]))
    g3.SetInt64(int64(f[3]))
    g4.SetInt64(int64(f[4]))

    var f1_19, f2_19, f3_19, f4_19 big.Int
    a19 := big.NewInt(19)
    f1_19.Mul(&f1, a19)
    f2_19.Mul(&f2, a19)
    f3_19.Mul(&f3, a19)
    f4_19.Mul(&f4, a19)

    r0.Add(&r0, f0.Mul(&f0, &g0)).Add(&r0, f1_19.Mul(&f1_19, &g4)).Add(&r0, f2_19.Mul(&f2_19, &g3)).Add(&r0, f3_19.Mul(&f3_19, &g2)).Add(&r0, f4_19.Mul(&f4_19, &g1))
	r1.Add(&r1, f0.Mul(&f0, &g1)).Add(&r1, f1.Mul(&f1, &g0)).Add(&r1, f2_19.Mul(&f2_19, &g4)).Add(&r1, f3_19.Mul(&f3_19, &g3)).Add(&r1, f4_19.Mul(&f4_19, &g2))
	r2.Add(&r2, f0.Mul(&f0, &g2)).Add(&r2, f1.Mul(&f1, &g1)).Add(&r2, f2.Mul(&f2, &g0)).Add(&r2, f3_19.Mul(&f3_19, &g4)).Add(&r2, f4_19.Mul(&f4_19, &g3))
	r3.Add(&r3, f0.Mul(&f0, &g3)).Add(&r3, f1.Mul(&f1, &g2)).Add(&r3, f2.Mul(&f2, &g1)).Add(&r3, f3.Mul(&f3, &g0)).Add(&r3, f4_19.Mul(&f4_19, &g4))
	r4.Add(&r4, f0.Mul(&f0, &g4)).Add(&r4, f1.Mul(&f1, &g3)).Add(&r4, f2.Mul(&f2, &g2)).Add(&r4, f3.Mul(&f3, &g1)).Add(&r4, f4.Mul(&f4, &g0))

    carries := new(big.Int)
    mask19 := new(big.Int)
    mask19.SetInt64(19)
    for i, list := [](*big.Int){&r0, &r1, &r2, &r3, &r4}, uint(0); i < len(list) && i+1 < len(list); i++ {
		list[i].And(list[i], snd)
		list[i+1].Add(list[i+1], list[i].Rsh(list[i], 51))

		if i == 4 {
			carries.Mul(carries.Rsh(list[0], 51), mask19)
			list[0].And(list[0], snd).Add(list[0], carries)
		}
	}

    h[0] = r0.Uint64()
    h[1] = r1.Uint64()
    h[2] = r2.Uint64()
    h[3] = r3.Uint64()
    h[4] = r4.Uint64()
}
