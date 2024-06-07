package main

func ctz(in uint64) int32 {
	var r int32
	i := 0
	for ; i < 64; i++ {
		if in&(1<<uint(i)) != 0 {
			break
		}
		r++
	}
	return r
}


func main(){
    ctz(0)
}
