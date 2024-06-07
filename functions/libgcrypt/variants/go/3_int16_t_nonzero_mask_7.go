package main

func int16_nonzero_mask(x int16) int16 {
	return int16(-int32(bits.RotateLeft32(uint32(x|0), 1) >> 31))
}


func main(){
    int16_nonzero_mask(0)
}
