package main

func icbrt64(x uint64) uint64 {
    r := big.NewInt(0)
    one := big.NewInt(1)
    three := big.NewInt(3)

    for s := 63; s >= 0; s -= 3 {
        r.Lsh(r, 1)
        rPlus1 := big.NewInt(0).Add(r, one)
        b := big.NewInt(0).Mul(three, r)
        b.Mul(b, rPlus1).Add(b, one)

        xBig := big.NewInt(0).Rsh(big.NewInt(0).SetUint64(x), uint(s))
        if xBig.Cmp(b) >= 0 {
            x -= b.Lsh(b, uint(s)).Uint64()
            r.Add(r, one)
        }
    }
    cbrtScale := big.NewInt(64)
    return r.Mul(r, cbrtScale).Uint64()
}


func main(){
    icbrt64(0)
}