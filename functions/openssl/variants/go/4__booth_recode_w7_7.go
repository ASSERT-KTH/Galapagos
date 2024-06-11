package main

func boothRecodeW7_7(in uint32) uint32 {
	s := ^((in >> 7) - 1)
	d := 255 - in
	d = (d & s) | (in & ^s)
	d = (d >> 1)
	if (d & 1) == 1 {
		d++
	}
	
	return (d << 1) + (s & 1)
}


func main(){
    boothRecodeW7_7(0)
}
