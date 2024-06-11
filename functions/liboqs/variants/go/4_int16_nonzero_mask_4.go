package main

func int16_nonzero_mask(x int16) int32 {
	u := uint32(x)
	if u != 0 {
		return -1
	}
	return 0
}


func main(){
    int16_nonzero_mask(0)
}
