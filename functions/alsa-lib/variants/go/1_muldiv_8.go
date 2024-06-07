package main

func muldiv(a, b, c int32, r *int32) int32 {
	const (
		MaxInt32 int32 = 2147483647
		MinInt32 int32 = -2147483648
	)
	n := int64(a) * int64(b)
	v := int32(n / int64(c))
	if v > MaxInt32 {
		*r = int32(0)
		return MaxInt32
	}
	if v < MinInt32 {
		*r = int32(0)
		return MinInt32
	}
	*r = int32(n % int64(c))
	return v
}


func main(){
    muldiv(0,0,0,0)
}
