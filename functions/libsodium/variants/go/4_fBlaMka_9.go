package main

func fBlaMka(x, y uint64) uint64 {
	const mask uint64 = 0xFFFFFFFF
	prod := (x & mask) * (y & mask)
	return (2 * prod) + x + y
}


func main(){
    fBlaMka(0,0)
}
