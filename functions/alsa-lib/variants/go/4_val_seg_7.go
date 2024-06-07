package main

func valSeg(val int32) int {
	r := 1
	val >>= 8
	for shift := 4; shift >= 1; shift /= 2 {
		if val & (0xff >> (4 - shift)) != 0 {
			val >>= shift
			r += shift
		}
	}
	return r
}


func main(){
    valSeg(0)
}
