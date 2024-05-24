package main

func fpr_lt(x int64, y int64) int32 {
	mask := ^((x ^ y) >> 63)
	sy := y & mask
	cc0 := int32((x - sy) >> 63) & 1
	cc1 := int32((sy - x) >> 63) & 1
	return cc0 ^ ((cc0 ^ cc1) & int32(((x & y)>>63)&1))
}


func main(){
    fpr_lt(0,0)
}
