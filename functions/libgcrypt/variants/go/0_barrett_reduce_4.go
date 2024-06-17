package main

func barrettReduce(a int16) int16 {
	const v = int16(((1 << 26) + 3329/2) / 3329)
	tmp := int32(a) * int32(v)
	tmp += 1 << 25
	tmp >>= 26
	tmp *= 3329
	return a - int16(tmp)
}


func main(){
    barrettReduce(0)
}