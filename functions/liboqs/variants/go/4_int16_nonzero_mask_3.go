package main

func int16_nonzero_mask(x int16) int32 {
	if x == 0 {
		return 0
	}
	return int32(-1)
}


func main(){
    int16_nonzero_mask(0)
}