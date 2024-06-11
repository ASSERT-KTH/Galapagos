package main

func fpr_half(x uint64) uint64 {
    frac := x & ((1 << 52) - 1)
    exp := (x >> 52) & 0x7FF
    if exp == 0 {
        return x >> 1
    }
    exp--
    return frac | (exp << 52)
}


func main(){
    fpr_half(0)
}
