package main

func fpr_lt(x, y uint64) int32 {
    if (x < (1 << 63)) == (y < (1 << 63)) {
        return int32((int64(x) - int64(y)) >> 63 & 1)
    } else if x < (1 << 63) {
        return 0
    }
    return 1
}


func main(){
    fpr_lt(0,0)
}
