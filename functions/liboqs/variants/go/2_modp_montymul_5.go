package main

func modp_montymul(a, b, p, p0i uint32) uint32 {
    z := uint64(a) * uint64(b)
    w := (z * uint64(p0i) & uint64(0x7FFFFFFF)) * uint64(p)
    d := uint32((z + w) >> 31)
    if d < p {
        return d
    }
    return d - p
}


func main(){
    modp_montymul(0,0,0,0)
}
