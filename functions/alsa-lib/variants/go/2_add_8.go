package main

func add(a uint32, b uint32) uint32 {
	if a > ^uint32(0)-b {
		return ^uint32(0)
	}
	return a + b
}


func main(){
    add(0,0)
}
