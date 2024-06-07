package main

func int16_nonzero_mask(x int16) int16 {
	y := uint16(x)
	z := uint32(y)
	return int16(-(z >> 31))
}


func main(){
    int16_nonzero_mask(0)
}
