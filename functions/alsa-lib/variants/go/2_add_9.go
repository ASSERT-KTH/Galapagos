package main

func add(a uint32, b uint32) uint32 {
	maxVal := uint32(4294967295)
	if a >= maxVal-b {
		return maxVal
	}
	return a + b
}


func main(){
    add(0,0)
}
