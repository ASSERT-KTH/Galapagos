package main

func int16_nonzero_mask(x int16) int16 {
	return int16(^uint16(x | -x >> 15) >> 15)
}


func main(){
    int16_nonzero_mask(0)
}
