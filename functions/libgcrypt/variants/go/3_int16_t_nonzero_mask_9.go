package main

func int16_t_nonzero_mask(x int16) int32 {
	return int32((uint32((x | -x)) >> 15) & 1) * -1
}


func main(){
    int16_t_nonzero_mask(0)
}
