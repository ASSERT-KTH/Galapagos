package main

func int16_t_nonzero_mask(x int16) int32 {
	return -int32(uint32(uint16(x)) >> 15)
}


func main(){
    int16_t_nonzero_mask(0)
}
