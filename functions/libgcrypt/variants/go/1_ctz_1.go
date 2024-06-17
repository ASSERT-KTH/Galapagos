package main

func ctz(in uint64) int32 {
	if in == 0 {
		return 64
	}

	var r int32
	for (in & 1) == 0 {
		r++
		in >>= 1
	}

	return r
}


func main(){
    ctz(0)
}