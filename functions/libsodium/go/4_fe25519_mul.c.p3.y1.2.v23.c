go
package main

import "math/big"

func fe25519_mul(h []uint64, f []uint64, g []uint64) {
    mask := uint64(0x7ffffffffffff)
    r0 := big.NewInt(0)
    r1 := big.NewInt(0)
    r2 := big.NewInt(0)
    r3 := big.NewInt(0)
    r4 := big.NewInt(0)

    f0 := big.NewInt(0).SetUint64(f[0])
    f1 := big.NewInt(0).SetUint64(f[1])
    f2 := big.NewInt(0).SetUint64(f[2])
    f3 := big.NewInt(0).SetUint64(f[3])
    f4 := big.NewInt(0).SetUint64(f[4])
  
    g0 := big.NewInt(0).SetUint64(g[0])
    g1 := big.NewInt(0).SetUint64(g[1])
    g2 := big.NewInt(0).SetUint64(g[2])
    g3 := big.NewInt(0).SetUint64(g[3])
    g4 := big.NewInt(0).SetUint64(g[4])

    f1_19 := new(big.Int).Mul(f1, big.NewInt(19))
    f2_19 := new(big.Int).Mul(f2, big.NewInt(19))
    f3_19 := new(big.Int).Mul(f3, big.NewInt(19))
    f4_19 := new(big.Int).Mul(f4, big.NewInt(19))
  
    r0.Add(f0.Mul(f0, g0), f1_19.Mul(f1_19, g4))
    tmp := new(big.Int).Mul(f0, g0).Add(r1, f1.Mul(f1, g0))
    r2.Add(tmp, f2_19.Mul(f2_19, g4)).Add(r2, f3_19.Mul(f3_19, g3)).Add(r2, f4_19.Mul(f4_19, g2))
    r3.Add(tmp, f1.Mul(f1, g2)).Add(r3, f2.Mul(f2, g1)).Add(r3, f3.Mul(f3, g0)).Add(tmp, f4.Mul(f4, g4))
    r4.Add(r0, f1.Mul(f1, g3)).Add(r4, f2.Mul(f2, g2)).Add(r4, f3.Mul(f3, g1)).Add(tmp, f4.Mul(f4, g0))
  
    r0.Text(10), _ := new(big.Int).SetString(r0.Text(10), 10)
    r1.Text(10), _ := new(big.Int).SetString(r1.Text(10), 10)
    r3.Text(10), _ := new(big.Int).SetString(r3.Text(10), 10)
    r4.Text(10), _ := new(big.Int).SetString(r4.Text(10), 10)
  
    r0.SetBit(r0, 51, r0.Bit(51)&uint(mask))
    carry, r1Bit := r1.Bit(51), big.NewInt(0).SetUint64(uint64(r1.Bit(51)))
    r1Bit.SetBit(r1Bit, 51, carry&mask)
    r3.Bit(51), carry = r3.Bit(51)&uint(mask), r4.Bit(51)
  
    h[0] = r0.Uint64()
    h[1] = r1.Uint64()
    h[2] = r2.Uint64()
    h[3] = r3.Uint64()
    h[4] = r4.Uint64()
}
