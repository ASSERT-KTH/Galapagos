package main

func fpr_half(x uint64) uint64 {
    if (x & (0x7FF << 52)) == 0 {
        return x >> 1
    }
    return (x & ((1 << 52) - 1)) | ((x - (1 << 52)) & (0x7FF << 52))
}


func main(){
    fpr_half(0)
}