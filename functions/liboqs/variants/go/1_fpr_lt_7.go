package main

func fpr_lt(x, y uint64) int32 {
    sx := int64(x)
    sy := int64(y)
    sign_x := sx >> 63
    sign_y := sy >> 63
    if sign_x != sign_y {
        return int32(sign_x & 1)
    }
    return int32((sx - sy) >> 63 & 1)
}


func main(){
    fpr_lt(0,0)
}