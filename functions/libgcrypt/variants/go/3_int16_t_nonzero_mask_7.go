package main

func int16_t_nonzero_mask(x int16) int32 {
	v := -uint32(uint16(x))
	return int32(v >> 31 & 1)
}


func main(){
    int16_t_nonzero_mask(0)
}