package main

func fBlaMka(x, y uint64) uint64 {
	const m uint64 = 0xFFFFFFFF
	lowBits := x & m
	combined := lowBits * (y & m)
	return x + y + combined*2
}


func main(){
    fBlaMka(0,0)
}
