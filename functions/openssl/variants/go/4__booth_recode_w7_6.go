package main

func boothRecodeW7_6(in uint32) uint32 {
	s := ^((in >> 7) - 1)
	d := 256 - in - 1
	d = (d & s) | (in & ^s)
	d = (d >> 1) + (d & 1)

	return (d << 1) + (s & 1)
}


func main(){
    boothRecodeW7_6(0)
}