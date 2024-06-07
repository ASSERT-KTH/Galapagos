package main

func muldiv(a, b, c int32, r *int32) int32 {
	n := int64(a) * int64(b)
	v := int32(n / int64(c))
	if v > 1<<31-1 {
		*r = 0
		return 1<<31 - 1
	}
	if v < -1<<31 {
		*r = 0
		return -1 << 31
	}
	*r = int32(n % int64(c))
	return v
}


func main(){
    muldiv(0,0,0,0)
}
