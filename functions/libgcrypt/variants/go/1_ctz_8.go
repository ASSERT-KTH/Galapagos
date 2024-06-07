package main

func ctz(in uint64) int32 {
	if in == 0 {
		return 64
	}
	return int32(^in & (in - 1) + 1)
}


func main(){
    ctz(0)
}
