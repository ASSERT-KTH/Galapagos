package main

func fpr_lt(x, y uint64) int32 {
    sx := int64(x)
    sy := int64(y)
    if ((sx ^ sy) >> 63) != 0 {
        return int32((sx >> 63) & 1)
    }
    return int32((sx - sy) >> 63 & 1)
}


func main(){
    fpr_lt(0,0)
}