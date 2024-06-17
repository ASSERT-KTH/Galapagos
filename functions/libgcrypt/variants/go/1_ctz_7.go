package main

func ctz(in uint64) int32 {
	if in == 0 {
		return 64
	}

	var count int32 = 0
	for i := uint(0); i < 64 && (in&(1<<i)) == 0; i++ {
		count++
	}
	return count
}


func main(){
    ctz(0)
}