package main

func fpr_half(x uint64) uint64 {
    if ((x >> 52) & 0x7FF) == 0 {
        return x >> 1
    }
    maskedX := x & ((1 << 52) - 1)
    exponent := ((x >> 52) - 1) << 52
    return maskedX | exponent
}


func main(){
    fpr_half(0)
}
