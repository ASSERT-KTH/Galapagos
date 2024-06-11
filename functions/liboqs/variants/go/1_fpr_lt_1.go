package main

func fpr_lt(x, y uint64) int32 {
    if int64(x) < int64(y) {
        return 1
    }
    return 0
}


func main(){
    fpr_lt(0,0)
}
