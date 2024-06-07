package main

func barrettReduce(a int16) int16 {
	const v = int16(((1 << 26) + 3329/2) / 3329)
	t := ((int32(a) * int32(v)) + (1 << 25)) >> 26
	return int16(int32(a) - t*3329)
}


func main(){
    barrettReduce(0)
}
