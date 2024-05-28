package main

func fpr_lt(x, y int64) int {
    sx := x
    sy := y
    sy &= ^((sx ^ sy) >> 63)

    cc0 := int((sx - sy) >> 63) & 1
    cc1 := int((sy - sx) >> 63) & 1

    return cc0 ^ ((cc0 ^ cc1) & int((x & y) >> 63))
}


func main(){
    fpr_lt(0,0)
}

