go
package main
  
import"math/big"
  
type fe25519 [5]uint64
  
func fe25519_mul(h, f, g fe25519) {
   const mask uint64 = 0x7ffffffffffff
  
   r0 := new(big.Int)
   r1 := new(big.Int)
   r2 := new(big.Int)
   r3 := new(big.Int)
   r4 := new(big.Int)  
  
   f1_19 := big.NewInt(0).Mul(big.NewInt(0).SetUint64(f[1]), big.NewInt(19))
   f2_19 := big.NewInt(0).Mul(big.NewInt(0).SetUint64(f[2]), big.NewInt(19))
   f3_19 := big.NewInt(0).Mul(big.NewInt(0).SetUint64(f[3]), big.NewInt(19))
   f4_19 := big.NewInt(0).Mul(big.NewInt(0).SetUint64(f[4]), big.NewInt(19))
    
   r0.Add(r0.Mul(big.NewInt(0).SetUint64(f[0]), big.NewInt(0).SetUint64(g[0])), big.NewInt(0).Add(big.NewInt(0).Add(big.NewInt(0).Add(big.NewInt(0).Mul(f1_19, (big.NewInt(0).SetUint64(g[4]))), big.NewInt(0).Mul(f2_19, big.NewInt(0).SetUint64(g[3]))), big.NewInt(0).Add(big.NewInt(0).Mul(f3_19, big.NewInt(0).SetUint64(g[2])), big.NewInt(0).Mul(f4_19, big.NewInt(0).SetUint64(g[1])))))
   r1.Add(r1.Mul(big.NewInt(0).SetUint64(f[0]), big.NewInt(0).SetUint64(g[1])), big.NewInt(0).Add(big.NewInt(0).Add(big.NewInt(0).Add(big.NewInt(0).Mul(big.NewInt(0).SetUint64(f[1]), (big.NewInt(0).SetUint64(g[0]))), big.NewInt(0).Mul(f2_19, big.NewInt(0).SetUint64(g[4]))), big.NewInt(0).Add(big.NewInt(0).Mul(f3_19, big.NewInt(0).SetUint64(g[3])), big.NewInt(0).Mul(f4_19, big.NewInt(0).SetUint64(g[2])))))
   r2.Add(r2.Mul(big.NewInt(0).SetUint64(f[0]), big.NewInt(0).SetUint64(g[2])), big.NewInt(0).Add(big.NewInt(0).Add(big.NewInt(0).Add(big.NewInt(0).Mul(big.NewInt(0).SetUint64(f[1]), (big.NewInt(0).SetUint64(g[1]))), big.NewInt(0).Mul(big.NewInt(0).SetUint64(f[2]), big.NewInt(0).SetUint64(g[0]))), big.NewInt(0).Add(big.NewInt(0).Mul(f3_19, big.NewInt(0).SetUint64(g[4])), big.NewInt(0).Mul(f4_19, big.NewInt(0).SetUint64(g[3])))))
   r3.Add(r3.Mul(big.NewInt(0).SetUint64(f[0]), big.NewInt(0).SetUint64(g[3])), big.NewInt(0).Add(big.NewInt(0).Add(big.NewInt(0).Add(big.NewInt(0).Mul(big.NewInt(0).SetUint64(f[1]), (big.NewInt(0).SetUint64(g[2]))), big.NewInt(0).Mul(big.NewInt(0).SetUint64(f[2]), big.NewInt(0).SetUint64(g[1]))), big.NewInt(0).Add(big.NewInt(0).Mul(big.NewInt(0).SetUint64(f[3]), big.NewInt(0).SetUint64(g[0])), big.NewInt(0).Mul(f4_19, big.NewInt(0).SetUint64(g[4])))))
   r4.Add(r4.Mul(big.NewInt(0).SetUint64(f[0]), big.NewInt(0).SetUint64(g[4])), big.NewInt(0).Add(big.NewInt(0).Add(big.NewInt(0).Add(big.NewInt(0).Mul(big.NewInt(0).SetUint64(f[1]), (big.NewInt(0).SetUint64(g[3]))), big.NewInt(0).Mul(big.NewInt(0).SetUint64(f[2]), big.NewInt(0).SetUint64(g[2]))), big.NewInt(0).Add(big.NewInt(0).Mul(big.NewInt(0).SetUint64(f[3]), big.NewInt(0).SetUint64(g[1])), big.NewInt(0).Mul(big.NewInt(0).SetUint64(f[4]), big.NewInt(0).SetUint64(g[0])))))

   var carry big.Int
   r00 := big.NewInt(0).And(r0, big.NewInt(0).SetUint64(mask))
   carry.Rsh(r0, 51)
   r1.Add(r1, &carry)
   r01 := big.NewInt(0).And(r1, big.NewInt(0).SetUint64(mask))
   carry.Rsh(r1, 51)
   r2.Add(r2, &carry)
   
   r02 := big.NewInt(0).And(r2, big.NewInt(0).SetUint64(mask))
   carry.Rsh(r2, 51)
   r3.Add(r3, &carry)
   r03 := big.NewInt(0).And(r3, big.NewInt(0).SetUint64(mask))
  
   carry.Rsh(r3, 51)
   r4.Add(r4, &carry)
   r04 := big.NewInt(0).And(r4, big.NewInt(0).SetUint64(mask))
   carry.Rsh(r4, 51)
   r00.Add(r00, big.NewInt(0).Mul(big.NewInt(19), &carry))
  
   carry.Rsh(r00, 51)
   r00.And(r00, big.NewInt(0).SetUint64(mask))
   r01.Add(r01, &carry)
   carry.Rsh(r01, 51)
   r01.And(r01, big.NewInt(0).SetUint64(mask))
   r02.Add(r02, &carry)

   h[0] = r00.Uint64()
   h[1] = r01.Uint64()
   h[2] = r02.Uint64()
   h[3] = r03.Uint64()
   h[4] = r04.Uint64()
}
