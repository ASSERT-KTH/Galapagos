package main

func int16_t_nonzero_mask(x int16) int32 {
	return int32(int32(x) >> 31 | int32(-x) >> 31)
}


func main(){
    int16_t_nonzero_mask(0)
}
