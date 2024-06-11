package main

func fBlaMka(x, y uint64) uint64 {
	const m uint64 = 0xFFFFFFFF
	xy := x & m
	xy *= y & m
	return x + y + (xy << 1)
}


func main(){
    fBlaMka(0,0)
}
