package main

func fBlaMka(x, y uint64) uint64 {
	const mask uint64 = 0xFFFFFFFF
	prod := (x & mask) * (y & mask)
	return x + y + 2*prod
}


func main(){
    fBlaMka(0,0)
}
