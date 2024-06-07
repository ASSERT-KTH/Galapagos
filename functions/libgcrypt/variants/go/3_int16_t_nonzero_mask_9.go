package main

func int16_nonzero_mask(x int16) int16 {
	return int16(-int32((uint32(x) | uint32(-x)) >> 31))
}


func main(){
    int16_nonzero_mask(0)
}
