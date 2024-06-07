package main

func ctz(in uint64) int32 {
	var r int32

	for i := 0; i < 64; i++ {
		if (in>>i)&1 != 0 {
			break
		}
		r++
	}

	return r
}


func main(){
    ctz(0)
}
