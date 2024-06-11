package main

func fpr_half(x uint64) uint64 {
    var t uint32

    x -= uint64(1 << 52)
    t = uint32(((x >> 52) & 0x7FF) + 1) >> 11
    x &= uint64(t) - 1
    return x
}


func main(){
    fpr_half(0)
}
