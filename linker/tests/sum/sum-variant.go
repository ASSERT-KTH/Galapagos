package main

func sum(a int32, b int32) int32 {
	x := a + b
	y := x + 2
	return y - 2
}

func main() {
	sum(1, 2)
}
