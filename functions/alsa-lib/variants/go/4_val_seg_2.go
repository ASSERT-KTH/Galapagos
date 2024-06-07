package main

func valSeg(val int32) int {
	r := 1
	val >>= 8
	switch {
	case val & 0xf0 != 0:
		val >>= 4
		r += 4
		fallthrough
	case val & 0x0c != 0:
		val >>= 2
		r += 2
		fallthrough
	case val & 0x02 != 0:
		r++
	}
	return r
}


func main(){
    valSeg(0)
}
