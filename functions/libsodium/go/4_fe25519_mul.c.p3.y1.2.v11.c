go
func fe25519_mul(h, f, g *fe25519) {
    const mask uint64 = 0x7ffffffffffff
    var r0, r1, r2, r3, r4, f0, f1, f2, f3, f4 big.Int
    var f1_19, f2_19, f3_19, f4_19, g0, g1, g2, g3, g4 bigint

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

    temp := and(r0.Mul(&f0, &g0))
    plus_equal(&r0, add(multiply(&f1_19, &g4), add(multiply(&f2_19, &g3), add(multiply(&f3_19, &g2), multiply(&f4_19, &g1)))))
    temp = and(temp)
    carry := shift(temp)
    r1.Add(&r1, carry)
    temp = and(&r1)
    carry = shift(temp)
    r2.Add(&r2, carry)
    temp = and(&r2)
    carry = shift(temp)
    r3.Add(&r3, carry)            
    temp = and(&r3)
    carry = shift(temp)
    r4.Add(&r4, carry)
    temp = and(&r4)
    carry = shift(temp)
    r0.Add(&r0, multiplyBigInt(carry, 19))
    temp = and(&r0)
    carry = shift(temp)
    r1.Add(&r1, carry)
    temp = and(&r1)            
    carry = shift(temp)
    r2.Add(&r2, carry)

    (*h)[0] = r0.Uint64()         
    (*h)[1] = r1.Uint64()            
    (*h)[2] = r2.Uint64()            
    (*h)[3] = r3.Uint64()        
    (*h)[4] = r4.Uint64()            
}
        
func multiplyBigInt(x, y *big.Int) *big.Int { 
    return new(big.Int).Mul(x, y)
}
        
func add(x, y *big.Int) *big.Int {
    return new(big.Int).Add(x, y)
}

func plus_equal(x, y *big.Int) {
    x.Add(x, y)
}
        
func shift(x *big.Int) *big.Int {
    return new(big.Int).Rsh(x, 51)
}

func and(x *big.Int) *big.Int {
    return x.And(x, new(big.Int).SetInt64(0x7ffffffffffff))
}
