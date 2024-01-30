func fe25519_mul(h []uint64, f []uint64, g []uint64) {
    const mask uint64 = 0x7ffffffffffff
	var r0, r1, r2, r3, r4 uint64
	var f0, f1, f2, f3, f4 uint64
	var f1_19, f2_19, f3_19, f4_19 uint64
	var g0, g1, g2, g3, g4 uint64
	var r00, r01, r02, r03, r04 uint64
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
	r0 = f0 * g0 + f1_19 * g4 + f2_19 * g3 + f3_19 * g2 + f4_19 * g1
	r1 = f0 * g1 + f1 * g0 + f2_19 * g4 + f3_19 * g3 + f4_19 * g2
	r2 = f0 * g2 + f1 * g1 + f2 * g0 + f3_19 * g4 + f4_19 * g3
	r3 = f0 * g3 + f1 * g2 + f2 * g1 + f3 * g0 + f4_19 * g4
	r4 = f0 * g4 + f1 * g3 + f2 * g2 + f3 * g1 + f4 * g0
	r00 = r0 & mask
	carry = r0 >> 51
	r1 += carry
	r01 = r1 & mask
	carry = r1 >> 51
	r2 += carry
	r02 = r2 & mask
	carry = r2 >> 51
	r3 += carry
	r03 = r3 & mask
	carry = r3 >> 51
	r4 += carry
	r04 = r4 & mask
	carry = r4 >> 51
	r00 += 19 * carry
	carry = r00 >> 51
	r00 &= mask
	r01 += carry
	carry = r01 >> 51
	r01 &= mask
	r02 += carry
	h[0] = r00
	h[1] = r01
	h[2] = r02
	h[3] = r03
	h[4] = r04
}