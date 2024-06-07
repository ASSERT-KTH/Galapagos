package main

func int16_nonzero_mask(x int16) int16 {
	return int16(int32((x >> 15) - (x >> 15 & 1)))
}


func main(){
    int16_nonzero_mask(0)
}
