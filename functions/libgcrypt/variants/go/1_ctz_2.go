package main

func ctz(in uint64) int32 {
	var r int32 = 0
	for ; (in & 1) == 0 && r < 64; r++ {
		in >>= 1
	}
	return r
}


func main(){
    ctz(0)
}
