package main

func int16_nonzero_mask(x int16) int32 {
	u := uint32(x)
	return -int32((u | -u) >> 31)
}


func main(){
    int16_nonzero_mask(0)
}
