package main

func valSeg(val int32) int {
	r := 1
	val >>= 8
	if (val >> 4) & 0x0f != 0 {
		val >>= 4
		r += 4
	}
	if (val >> 2) & 0x03 != 0 {
		val >>= 2
		r += 2
	}
	if (val >> 1) & 0x01 != 0 {
		r += 1
	}
	return r
}


func main(){
    valSeg(0)
}
