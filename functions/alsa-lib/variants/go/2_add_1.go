package main

func add(a uint32, b uint32) uint32 {
	max := uint32(4294967295)
	sum := a + b
	if sum < a || sum < b {
		return max
	}
	return sum
}


func main(){
    add(0,0)
}