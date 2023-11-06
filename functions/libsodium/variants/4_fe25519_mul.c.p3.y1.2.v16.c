func fe25519_mul(h, f, g [5]uint64) {
   const mask uint64 = 0x7ffffffffffff
   var r0, r1, r2, r3, r4 uint128.Int
   var f0, f1, f2, f3, f4 uint128.Int
   var f1_19, f2_19, f3_19, f4_19 uint128.Int
   var g0, g1, g2, g3, g4 uint128.Int
   var r00, r01, r02, r03, r04 uint64
   var carry uint64

   f0 = uint128.From64(f[0])
   f1 = uint128.From64(f[1])
   f2 = uint128.From64(f[2])
   f3 = uint128.From64(f[3])
   f4 = uint128.From64(f[4])

   g0 = uint128.From64(g[0])
   g1 = uint128.From64(g[1])
   g2 = uint128.From64(g[2])
   g3 = uint128.From64(g[3])
   g4 = uint128.From64(g[4])

   f1_19 = uint128.Mul(f1, 19)
   f2_19 = uint128.Mul(f2, 19)
   f3_19 = uint128.Mul(f3, 19)
   f4_19 = uint128.Mul(f4, 19)

   r0 = uint128.Add(uint128.Add(uint128.Add(uint128.Add(uint128.Mul(f0, g0), uint128.Mul(f1_19, g4)), uint128.Mul(f2_19, g3)), uint128.Mul(f3_19, g2)), uint128.Mul(f4_19, g1))
   r1 = uint128.Add(uint128.Add(uint128.Add(uint128.Add(uint128.Mul(f0, g1), uint128.Mul(f1, g0)), uint128.Mul(f2_19, g4)), uint128.Mul(f3_19, g3)), uint128.Mul(f4_19, g2))
   r2 = uint128.Add(uint128.Add(uint128.Add(uint128.Add(uint128.Mul(f0, g2), uint128.Mul(f1, g1)), uint128.Mul(f2, g0)), uint128.Mul(f3_19, g4)), uint128.Mul(f4_19, g3))
   r3 = uint128.Add(uint128.Add(uint128.Add(uint128.Add(uint128.Mul(f0, g3), uint128.Mul(f1, g2)), uint128.Mul(f2, g1)), uint128.Mul(f3, g0)), uint128.Mul(f4_19, g4))
   r4 = uint128.Add(uint128.Add(uint128.Add(uint128.Add(uint128.Mul(f0, g4), uint128.Mul(f1, g3)), uint128.Mul(f2, g2)), uint128.Mul(f3, g1)), uint128.Mul(f4, g0))

   r00 = r0.Lo & mask
   carry = r0.Hi()
   r1.Add(r1, uint128.From64(carry))
   r01 = r1.Lo & mask
   carry = r1.Hi()
   r2.Add(r2, uint128.From64(carry))
   r02 = r2.Lo & mask
   carry = r2.Hi()
   r3.Add(r3, uint128.From64(carry))
   r03 = r3.Lo & mask
   carry = r3.Hi()
   r4.Add(r4, uint128.From64(carry))
   r04 = r4.Lo & mask
   carry = r4.Hi()
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