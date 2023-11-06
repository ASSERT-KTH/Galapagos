Here is the equivalent code in Go:

go
func fe25519Mul(h *[5]uint64, f *[5]uint64, g *[5]uint64) {
	const mask  uint64 = 0x7ffffffffffff;
        const prime uint64 = 19;
        var carry, r0, r1, r2, r3, r4 uint128;
	
	f1_19 := prime * uint128(f[1])
	f2_19 := prime * uint128(f[2])
	f3_19 := prime * uint128(f[3])
	f4_19 := prime * uint128(f[4])

	r0 = uint128(f[0])*uint128(g[0]) + f4_19*uint128(g[1]) + f3_19*uint128(g[2]) + f2_19*uint128(g[3]) + f1_19*uint128(g[4])
	r1 = uint128(f[0])*uint128(g[1]) + uint128(f[1])*uint128(g[0]) + f4_19*uint128(g[2]) + f3_19*uint128(g[3]) + f2_19*uint128(g[4])
	r2 = uint128(f[0])*uint128(g[2]) + uint128(f[1])*uint128(g[1]) + uint128(f[2])*uint128(g[0]) + f4_19*uint128(g[3]) + f3_19*uint128(g[4])
	r3 = uint128(f[0])*uint128(g[3]) + uint128(f[1])*uint128(g[2]) + uint128(f[2])*uint128(g[1]) + uint128(f[3])*uint128(g[0]) + f4_19*uint128(g[4])
	r4 = uint128(f[0])*uint128(g[4]) + uint128(f[1])*uint128(g[3]) + uint128(f[2])*uint128(g[2]) + uint128(f[3])*uint128(g[1]) + uint128(f[4])*uint128(g[0])

	h[0] = r0.lower()
	carry = r0.upper()
        
	r1 = r1 + carry
	h[1] = r1.lower()
	carry = r1.upper()
	
	r2 = r2 + carry
	h[2] = r2.lower()
	carry = r2.upper()

	r3 = r3 + carry
	h[3] = r3.lower()
	carry = r3.upper()

	r4 = r4 + carry
	h[4] = r4.lower()
	carry = r4.upper()
	
	h[0] += carry * 19
	carry, h[0] = bits.Mul64(h[0], prime)
	h[0] &= mask

	carry, h[1] = bits.Add64(h[1], carry, 0)
	h[1] &= mask

	_, h[2] = bits.Add64(h[2], carry, 0)
}

Please note give uint128 doesn't exist as a built-in type in Go. You'll need a third-party library which provides a 128-bit integer type, or some emulation of 128-bit arithmetic with 64-bit numbers, it was used to make it more semantically similar with the original C code.