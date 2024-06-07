package main

func valSeg(val int32) int {
	r := 1
	val >>= 8
	bitLength := [5]int{0, 0, 1, 2, 4}
	for i := 4; i > 0; i-- {
		if val >= (1 << (bitLength[i] - 1)) {
			val >>= bitLength[i]
			r += bitLength[i]
		}
	}
	return r
}


func main(){
    valSeg(0)
}
