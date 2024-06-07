package main

func barrettReduce(a int16) int16 {
	const v = int16(((1 << 26) + 3329/2) / 3329)
	temp := int32(v)*int32(a) + (1 << 25)
	temp >>= 26
	temp *= 3329
	return int16(int32(a) - temp)
}


func main(){
    barrettReduce(0)
}
