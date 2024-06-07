package main

func muldivDown(a, b, c int32) int32 {
	const maxInt32 = 2147483647
	const minInt32 = -2147483648

	v := (int64(a) * int64(b)) / int64(c)
	if v > int64(maxInt32) {
		return maxInt32
	}
	if v < int64(minInt32) {
		return minInt32
	}
	return int32(v)
}


func main(){
    muldivDown(0,0,0)
}
