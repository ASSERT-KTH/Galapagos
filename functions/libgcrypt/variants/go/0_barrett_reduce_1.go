package main

func barrettReduce(a int16) int16 {
	const v int16 = ((1 << 26) + 3329/2) / 3329
	t := (int32(v)*int32(a) + (1 << 25)) >> 26
	t = t * 3329
	return int16(int32(a) - t)
}


func main(){
    barrettReduce(0)
}
