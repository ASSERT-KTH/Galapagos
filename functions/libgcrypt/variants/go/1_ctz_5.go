package main

func ctz(in uint64) int32 {
	for i := int32(0); i < 64; i++ {
		if (in>>uint(i))&1 == 1 {
			return i
		}
	}
	return 64
}


func main(){
    ctz(0)
}
