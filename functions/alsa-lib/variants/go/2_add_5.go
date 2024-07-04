package main

func add(a uint32, b uint32) uint32 {
	maxUint := uint32(4294967295)
	c := a + b
	if c > maxUint {
		return maxUint
	}
	if c < a {
		return maxUint
	}
	return c
}


func main(){
    add(0,0)
}
