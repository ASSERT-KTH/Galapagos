package main

func fpr_lt(x, y uint64) int32 {
    sx := int64(x)
    sy := int64(y)
    sign_diff := (sx ^ sy) >> 63
    sy &= ^sign_diff
    cc0 := (sx - sy) >> 63 & 1
    cc1 := (sy - sx) >> 63 & 1
    return int32(cc0 ^ (cc0 ^ cc1) & ((x & y) >> 63 & 1))
}


func main(){
    fpr_lt(0,0)
}
