go
type Fe25519 struct {
	data [5]uint64
}

func (h *Fe25519) fe25519_mul(f, g *Fe25519) {
	const mask uint64 = 0x7ffffffffffff
	type uint128 struct {
		low, high uint64
	}

	var (
		r0, r1, r2, r3, r4   uint128
		f0, f1, f2, f3, f4   uint64
		f1_19, f2_19, f3_19, f4_19   uint64
		g0, g1, g2, g3, g4   uint64
		r00, r01, r02, r03, r04 uint64
		carry uint64
	)

	f0 = f.data[0]
	f1 = f.data[1]
	f2 = f.data[2]
	f3 = f.data[3]
	f4 = f.data[4]

	g0 = g.data[0]
	g1 = g.data[1]
	g2 = g.data[2]
	g3 = g.data[3]
	g4 = g.data[4]

	f1_19 = 19 * f1
	f2_19 = 19 * f2
	f3_19 = 19 * f3
	f4_19 = 19 * f4

	r0.low = f0*g0 + f1_19*g4 + f2_19*g3 + f3_19*g2 + f4_19*g1
	r1.low = f0*g1 + f1*g0 + f2_19*g4 + f3_19*g3 + f4_19*g2
	r2.low = f0*g2 + f1*g1 + f2*g0 + f3_19*g4 + f4_19*g3
	r3.low = f0*g3 + f1*g2 + f2*g1 + f3*g0 + f4_19*g4
	r4.low = f0*g4 + f1*g3 + f2*g2 + f3*g1 + f4*g0

	r00 = r0.low & mask
	carry = r0.low >> 51
	r1.low += carry
	r01 = r1.low & mask
	carry = r1.low >> 51
	r2.low += carry
	r02 = r2.low & mask
	carry = r2.low >> 51
	r3.low += carry
	r03 = r3.low & mask
	carry = r3.low >> 51
	r4.low += carry
	r04 = r4.low & mask
	carry = r4.low >> 51
	r00 += 19 * carry
	carry = r00 >> 51
	r00 &= mask
	r01 += carry
	carry = r01 >> 51
	r01 &= mask
	r02 += carry

	h.data[0] = r00
	h.data[1] = r01
	h.data[2] = r02
	h.data[3] = r03
	h.data[4] = r04
}
