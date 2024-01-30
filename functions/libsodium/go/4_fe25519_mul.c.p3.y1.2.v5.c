Below is the Go implementation of the given C function:

go
type Fe25519 [5]uint64
type uint128 struct {
	low  uint64
	high uint64
}

func fe25519_mul(h, f, g *Fe25519) {
	const mask = 0x7ffffffffffff
	var r0, r1, r2, r3, r4 uint128
	var f0, f1, f2, f3, f4 uint128
	var f1_19, f2_19, f3_19, f4_19 uint128
	var g0, g1, g2, g3, g4 uint128
	var r00, r01, r02, r03, r04, carry uint64

	f0 = uint128{f[0], 0}
	f1 = uint128{f[1], 0}
	f2 = uint128{f[2], 0}
	f3 = uint128{f[3], 0}
	f4 = uint128{f[4], 0}

	g0 = uint128{g[0], 0}
	g1 = uint128{g[1], 0}
	g2 = uint128{g[2], 0}
	g3 = uint128{g[3], 0}
	g4 = uint128{g[4], 0}

	f1_19 = mul64x64(19, f1.low)
	f2_19 = mul64x64(19, f2.low)
	f3_19 = mul64x64(19, f3.low)
	f4_19 = mul64x64(19, f4.low)

	r0 = addx5(mul64x64(f0.low, g0.low), mul64x64(f1_19.low, g4.low), mul64x64(f2_19.low, g3.low), mul64x64(f3_19.low, g2.low), mul64x64(f4_19.low, g1.low))
	r1 = addx5(mul64x64(f0.low, g1.low), mul64x64(f1.low, g0.low), mul64x64(f2_19.low, g4.low), mul64x64(f3_19.low, g3.low), mul64x64(f4_19.low, g2.low))
	r2 = addx5(mul64x64(f0.low, g2.low), mul64x64(f1.low, g1.low), mul64x64(f2.low, g0.low), mul64x64(f3_19.low, g4.low), mul64x64(f4_19.low, g3.low))
	r3 = addx5(mul64x64(f0.low, g3.low), mul64x64(f1.low, g2.low), mul64x64(f2.low, g1.low), mul64x64(f3.low, g0.low), mul64x64(f4_19.low, g4.low))
	r4 = addx5(mul64x64(f0.low, g4.low), mul64x64(f1.low, g3.low), mul64x64(f2.low, g2.low), mul64x64(f3.low, g1.low), mul64x64(f4.low, g0.low))

	r00, carry = r0.low&mask, r0.low>>51
	r1.low += carry
	r01, carry = r1.low&mask, r1.low>>51
	r2.low += carry
	r02, carry = r2.low&mask, r2.low>>51
	r3.low += carry
	r03, carry = r3.low&mask, r3.low>>51
	r4.low += carry
	r04, carry = r4.low&mask, r4.low>>51
	r00, _ += mul64x64(19, carry)
	carry = r00 >> 51
	r00 &= mask
	r01 += carry
	carry = r01 >> 51
	r01 &= mask
	r02 += carry

	(*h)[0], (*h)[1], (*h)[2], (*h)[3], (*h)[4] = r00, r01, r02, r03, r04
}


Please note: 

This kind of code requires having the `mul64x64` (which multiplies two 64-bit ints into 128 bit ints) and `addx5` (which adds five 128 bit ints to each other) as available functions due to Go's builtin functions. This could look like in the following implementations:

go
func mul64x64(x, y uint64) uint128 {
	z1, z0 := bits.Mul64(x, y)
	return uint128{z0, z1}
}

func addx5(z, w, x, y, b uint128) uint128 {
	h0, l0 := bits.Add64(z.low, w.low, 0)
	h1, _ := bits.Add64(h0, x.low, 0)
	h2, _ := bits.Add64(h1, y.low, 0)
	h3, _ := bits.Add64(h2, b.low, 0)
	return uint128{h3, 0}
}
 

Please be aware those implementations could improve theoretical performance. If there is no need for highest performance care, `mul64x64` and `addx5` can just simply can `return x * y` and `return z + w + x + y + b` respectively. 

Important: Optimization level could depend on your Go compiler or Go runtime's handling for these specific bitwise/manipulations like addition, multiplication or binary shifts.