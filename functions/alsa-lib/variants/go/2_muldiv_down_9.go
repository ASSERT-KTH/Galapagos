package main

func muldiv_down(a int32, b int32, c int32) int32 {
	v := (int64(a) * int64(b)) / int64(c)
	if v > int64(int32(^uint32(0)>>1)) {
		return int32(^uint32(0) >> 1)
	}
	if v < int64(int32(^uint32(0)>>1)+1) {
		return int32(^uint32(0)>>1) + 1
	}
	return int32(v)
}


func main(){
    muldiv_down(0,0,0)
}