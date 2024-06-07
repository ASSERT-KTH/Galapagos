package main

func muldiv(a, b, c int32, r *int32) int32 {
	n := int64(a) * int64(b)
	v := int32(n / int64(c))
	if v > int32(2147483647) {
		*r = 0
		return 2147483647
	}
	if v < int32(-(2147483648)) {
		*r = 0
		return -2147483648
	}
	*r = int32(n % int64(c))
	return v
}


func main(){
    muldiv(0,0,0,0)
}
