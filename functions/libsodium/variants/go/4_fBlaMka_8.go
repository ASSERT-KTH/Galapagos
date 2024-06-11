package main

func fBlaMka(x, y uint64) uint64 {
	const mask uint64 = 0xFFFFFFFF
	xy := (x & mask) * (y & mask)
	return x + y + (xy * 2)
}


func main(){
    fBlaMka(0,0)
}
