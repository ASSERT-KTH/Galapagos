package main

func add(a uint32, b uint32) uint32 {
	max := uint32(4294967295)
	if safe := max - a; b > safe {
		return max
	}
	return a + b
}


func main(){
    add(0,0)
}