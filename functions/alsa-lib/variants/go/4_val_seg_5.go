package main

func valSeg(val int32) int {
	r := 1
	val >>= 8
	diff := (val & 0xf0)>>4 + (val & 0x0c)>>2 + (val & 0x02)
	r += int(diff)
	return r
}


func main(){
    valSeg(0)
}
