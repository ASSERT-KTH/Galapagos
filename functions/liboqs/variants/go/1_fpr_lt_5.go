package main

func fpr_lt(x, y uint64) int32 {
    if (x >> 63 == y >> 63) {
        return int32((int64(x) - int64(y)) >> 63 & 1)
    }
    if x >> 63 == 1 {
        return 1
    }
    return 0
}


func main(){
    fpr_lt(0,0)
}
