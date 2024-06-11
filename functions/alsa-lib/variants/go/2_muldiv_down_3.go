package main

func muldiv_down(a int32, b int32, c int32) int32 {
	v := int64(a)*int64(b)/int64(c)
	if v > math.MaxInt32 {
		return int32(math.MaxInt32)
	}
	if v < math.MinInt32 {
		return int32(math.MinInt32)
	}
	return int32(v)
}


func main(){
    muldiv_down(0,0,0)
}
