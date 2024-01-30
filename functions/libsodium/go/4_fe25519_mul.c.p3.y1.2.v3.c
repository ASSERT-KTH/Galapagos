go
type Fe25519 [5]uint64
type uint128 struct {
	High uint64
	Low  uint64
}

const mask = uint64(0x7ffffffffffff)

func fe25519Mul(h, f, g *Fe25519) {
	var r0, r1, r2, r3, r4 uint128
	var f1_19, f2_19, f3_19, f4_19 uint128
	var carry uint64

	f0 := f[0]
	f1 := f[1]
	f2 := f[2]
	f3 := f[3]
	f4 := f[4]

	g0 := g[0]
	g1 := g[1]
	g2 := g[2]
	g3 := g[3]
	g4 := g[4]

	f1_19 = mul64x64_128(19, f1)
	f2_19 = mul64x64_128(19, f2)
	f3_19 = mul64x64_128(19, f3)
	f4_19 = mul64x64_128(19, f4)

	r0 = add128(add128(add128(add128(mul64x64_128(f0, g0), mul64x64_128(f1_19.High, g4)), mul64x64_128(f2_19.High, g3)), mul64x64_128(f3_19.High, g2)), mul64x64_128(f4_19.High, g1))
	r1 = add128(add128(add128(add128(mul64x64_128(f0, g1), mul64x64_128(f1, g0)), mul64x64_128(f2_19.High, g4)), mul64x64_128(f3_19.High, g3)), mul64x64_128(f4_19.High, g2))
	r2 = add128(add128(add128(add128(mul64x64_128(f0, g2), mul64x64_128(f1, g1)), mul64x64_128(f2, g0)), mul64x64_128(f3_19.High, g4)), mul64x64_128(f4_19.High, g3))
	r3 = add128(add128(add128(add128(mul64x64_128(f0, g3), mul64x64_128(f1, g2)), mul64x64_128(f2, g1)), mul64x64_128(f3, g0)), mul64x64_128(f4_19.High, g4))
	r4 = add128(add128(add128(add128(mul64x64_128(f0, g4), mul64x64_128(f1, g3)), mul64x64_128(f2, g2)), mul64x64_128(f3, g1)), mul64x64_128(f4, g0))

	h[0], carry = shrAndCarry128(r0, 51)
	r1 = add128c(r1, 0, carry)
	h[1], carry = shrAndCarry128(r1, 51)
	r2 = add128c(r2, 0, carry)
	h[2], carry = shrAndCarry128(r2, 51)
	r3 = add128c(r3, 0, carry)
	h[3], carry = shrAndCarry128(r3, 51)
	r4 = add128c(r4, 0, carry)
	h[4], carry = shrAndCarry128(r4, 51)

	h[0] = (h[0] + 19*carry) & mask
	carry = h[0] >> 51
	h[0] &= mask

	h[1] += carry
	carry = h[1] >> 51
	h[0] &= mask
	h[1] += carry

	return
}

func mul64x64_128(a, b uint64) uint128 {
	return uint128{a * b, 0}
}

func shrAndCarry128(a uint128, n uint) (b uint64, carry uint64) {
	b = (a.Low >> n) + (a.High << (64 - n))
	carry = a.Low & ((1 << n) - 1)
	return b, carry
}

func add128c(a uint128, b uint, c uint64) uint128 {
	low, carry := add64Carry(a.Low, c)
	return uint128{
		High: carry + a.High + low,
		Low:  low,
	}
}

func add64Carry(a, b uint64) (low uint64, carry uint64) {
	low = a + b
	if low < a || low < b { 
		carry = 1 
	} 
	return
}
