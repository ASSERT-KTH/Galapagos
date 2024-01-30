Here is an implementation of the function in Go:

go
func fe25519_mul(h *[5]uint64, f *[5]uint64, g *[5]uint64) {
	const mask uint64 = 0x7ffffffffffff
	var r0, r1, r2, r3, r4 big.Int
	var f0, f1, f2, f3, f4 big.Int
	var f1_19, f2_19, f3_19, f4_19 big.Int
	var g0, g1, g2, g3, g4 big.Int
	var carry uint64

	f0.SetUint64(uint64((*f)[0]))
	f1.SetUint64(uint64((*f)[1]))
	f2.SetUint64(uint64((*f)[2]))
	f3.SetUint64(uint64((*f)[3]))
	f4.SetUint64(uint64((*f)[4]))

	g0.SetUint64(uint64((*g)[0]))
	g1.SetUint64(uint64((*g)[1]))
	g2.SetUint64(uint64((*g)[2]))
	g3.SetUint64(uint64((*g)[3]))
	g4.SetUint64(uint64((*g)[4]))

	f1_19.Mul(&f1, big.NewInt(19))
	f2_19.Mul(&f2, big.NewInt(19))
	f3_19.Mul(&f3, big.NewInt(19))
	f4_19.Mul(&f4, big.NewInt(19))

	r0.Add(&r0, r0.Mul(&f0, &g0)).Add(&r0, r1.Mul(&f1_19, &g4)).
		Add(&r0, r2.Mul(&f2_19, &g3)).Add(&r0, r3.Mul(&f3_19, &g2)).
		Add(&r0, r4.Mul(&f4_19, &g1))
	r1.Add(&r1, r1.Mul(&f0, &g1)).Add(&r1, r1.Mul(&f1, &g0)).
		Add(&r1, r2.Mul(&f2_19, &g4)).Add(&r1, r3.Mul(&f3_19, &g3)).
		Add(&r1, r4.Mul(&f4_19, &g2))
	r2.Add(&r2, r2.Mul(&f0, &g2)).Add(&r2, r2.Mul(&f1, &g1)).
		Add(&r2, r2.Mul(&f2, &g0)).Add(&r2, r3.Mul(&f3_19, &g4)).
		Add(&r2, r4.Mul(&f4_19, &g3))
	r3.Add(&r3, r3.Mul(&f0, &g3)).Add(&r3, r3.Mul(&f1, &g2)).
		Add(&r3, r3.Mul(&f2, &g1)).Add(&r3, r3.Mul(&f3, &g0)).
		Add(&r3, r4.Mul(&f4_19, &g4))
	r4.Add(&r4, r4.Mul(&f0, &g4)).Add(&r4, r4.Mul(&f1, &g3)).
		Add(&r4, r4.Mul(&f2, &g2)).Add(&r4, r4.Mul(&f3, &g1)).
		Add(&r4, r4.Mul(&f4, &g0))

	carry = uint64(r0.Uint64() >> 51)
	r0.SetBit(&r0, 51, 0)
	r1.Add(&r1, big.NewInt(int64(carry)))
	carry = uint64(r1.Uint64() >> 51)
	r1.SetBit(&r1, 51, 0)
	r2.Add(&r2, big.NewInt(int64(carry)))
	carry = uint64(r2.Uint64() >> 51)
	r2.SetBit(&r2, 51, 0)
	r3.Add(&r3, big.NewInt(int64(carry)))
	carry = uint64(r3.Uint64() >> 51)
	r3.SetBit(&r3, 51, 0)
	r4.Add(&r4, big.NewInt(int64(carry)))
	carry = uint64(r4.Uint64() >> 51)
	r4.SetBit(&r4, 51, 0)
	carry *= 19
	r0.Add(&r0, big.NewInt(int64(carry)))
	carry = uint64(r0.Uint64() >> 51)
	r0.SetBit(&r0, 51, 0)
	r1.Add(&r1, big.NewInt(int64(carry)))
	carry = uint64(r1.Uint64() >> 51)
	r1.SetBit(&r1, 51, 0)
	r2.Add(&r2, big.NewInt(int64(carry)))

    (*h)[0] = r0.Uint64()
    (*h)[1] = r1.Uint64()
    (*h)[2] = r2.Uint64()
    (*h)[3] = r3.Uint64()
    (*h)[4] = r4.Uint64()
}

Note that in Go, big computations such as this become practically harder regarding using a multitude of big integer math using the "math/big" library. This implementation converts the `uint64` bottom to `*big.Int` (pointer), does the necessary `big.Int` multiplication, and adds the value to an accumulating big integer variable (r0-r4), and then transfer it back. Bit twiddling and carrying of bits become a more significant effort.