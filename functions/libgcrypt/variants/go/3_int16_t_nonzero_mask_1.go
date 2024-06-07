package main

func int16_nonzero_mask(x int16) int16 {
	if x > 0 || x < 0 {
		return -1
	}
	return 0
}


func main(){
    int16_nonzero_mask(0)
}
