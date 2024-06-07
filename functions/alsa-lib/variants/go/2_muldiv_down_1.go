package main

func muldivDown(a, b, c int32) int32 {
	v := int64(a) * int64(b) / int64(c)
	if v > int64(math.MaxInt32) {
		return math.MaxInt32
	}
	if v < int64(math.MinInt32) {
		return math.MinInt32
	}
	return int32(v)
}


func main(){
    muldivDown(0,0,0)
}
