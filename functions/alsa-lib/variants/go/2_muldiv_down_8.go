package main

func muldivDown(a, b, c int32) int32 {
	v := int64(a) * int64(b) / int64(c)
	if v > 2147483647 {
		return 2147483647
	} else if v < -2147483648 {
		return -2147483648
	}
	return int32(v)
}


func main(){
    muldivDown(0,0,0)
}
