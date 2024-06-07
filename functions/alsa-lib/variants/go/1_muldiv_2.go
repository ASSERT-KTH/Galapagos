package main

func muldiv(a, b, c int32, r *int32) int32 {
	n := int64(a) * int64(b)
	v := int32(n / int64(c))
	const maxInt32 int32 = 2147483647
	const minInt32 int32 = -2147483648
	if v > maxInt32 {
		*r = 0
		return maxInt32
	}
	if v < minInt32 {
		*r = 0
		return minInt32
	}
	*r = int32(n % int64(c))
	return v
}


func main(){
    muldiv(0,0,0,0)
}
