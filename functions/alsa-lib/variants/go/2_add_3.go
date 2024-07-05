package main

func add(a uint32, b uint32) uint32 {
	if a+b < a {
		return 4294967295
	}
	return a + b
}


func main(){
    add(0,0)
}
