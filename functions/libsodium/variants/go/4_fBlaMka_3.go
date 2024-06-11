package main

func fBlaMka(x, y uint64) uint64 {
	const m uint64 = 0xFFFFFFFF
	partial := (x & m) * (y & m)
	return x + y + 2*(partial)
}


func main(){
    fBlaMka(0,0)
}
