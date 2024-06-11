package main

func muldiv_down(a int32, b int32, c int32) int32 {
	v := int64(a) * int64(b) / int64(c)
	if v > 2147483647 {
		return 2147483647
	}
	if v < -2147483648 {
		return -2147483648
	}
	return int32(v)
}


func main(){
    muldiv_down(0,0,0)
}
