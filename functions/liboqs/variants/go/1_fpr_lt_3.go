package main

func fpr_lt(x, y uint64) int32 {
    if (int64(x) & int64(y)) >= 0 {
        return int32((int64(x) - int64(y)) >> 63)
    }
    if int64(x) < 0 {
        return 1
    }
    return 0
}


func main(){
    fpr_lt(0,0)
}
