package main

func add(a uint32, b uint32) uint32 {
	var max uint32 = 4294967295
	if a > max-b {
		return max
	}
	return a + b
}


func main(){
    add(0,0)
}
