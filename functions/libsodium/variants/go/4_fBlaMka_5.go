package main

func fBlaMka(x, y uint64) uint64 {
	const mask uint64 = 0xFFFFFFFF
	temp := (x & mask) * (y & mask)
	result := x + y + (temp << 1)
	return result
}


func main(){
    fBlaMka(0,0)
}