package main

func ctz(in uint64) int32 {
	var r int32
	i := uint(0)
	for (in>>(63-i))&1 == 0 {
		r++
		i++
		if i >= 64 {
			break
		}
	}
	return r
}


func main(){
    ctz(0)
}