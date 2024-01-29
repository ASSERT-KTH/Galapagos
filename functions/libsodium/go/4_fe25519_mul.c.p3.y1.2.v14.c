Go
package main

import (
	"math/big"
)

func fe25519_mul(h *[5]uint64, f, g *[5]uint64)  {
	var mask uint64 = 0X7FFFFFFFFFFFF
	var r [5]big.Int
	var f_multiplied_by_19 [4]big.Int
	var carry *big.Int
	var carry_in_uint64 uint64
	var r_in_uint64 [5]uint64
	
	for i := 1; i < 5; i++ {
		f_multiplied_by_19[i - 1].Mul(big.NewInt(0).SetUint64(f[i]), big.NewInt(19))
	}
	
	r[0].Add(&r[0], f_multiplied_by_19[3])
	r[0].Mul(&r[0], big.NewInt(0).SetUint64(g[4]))

	carry, _ = r[0].DivMod(&r[0], big.NewInt(1<<51), &r[0])
	r_in_uint64[0] = r[i].Uint64()

	for i := 1; i < 5; i++ {
		r[i].Add(&r[i], f_multiplied_by_19[2-i])
		r[i].Mul(&r[i], big.NewInt(0).SetUint64(g[4-i]))

		r[i].Add(&r[i], big.NewInt(0).SetUint64(f[0]))
		r[i].Mul(&r[i], big.NewInt(0).SetUint64(g[i]))

		carry_in_uint64 = carry.Uint64()
		r[i].Add(&r[i], big.NewInt(0).SetUint64(carry_in_uint64))

		carry, _ = r[i].DivMod(&r[i], big.NewInt(1<<51), &r[i])
		r_in_uint64[i] = r[i].Uint64()
	}

	carry_in_uint64 = carry.Uint64()
	r_in_uint64[0] += 19 * carry_in_uint64;
	carry_in_uint64 = r_in_uint64[0] >> 51;
	r_in_uint64[0] &= mask;
	r_in_uint64[1] += carry_in_uint64;
	carry_in_uint64 = r_in_uint64[1] >> 51;
	r_in_uint64[1] &= mask;
	r_in_uint64[2] += carry_in_uint64;
	
	for i := 0; i < 5; i++ {
		h[i] = r_in_uint64[i]
	}
}
