package main

func alawToS16(aVal byte) int32 {
	aVal ^= 0x55
	t := int32(aVal & 0x7f)
	if t < 16 {
		t = t*16 + 8
	} else {
		seg := (t / 16) & 0x07
		t = 0x108 + (t%16)*16
		t = t << (seg - 1)
	}
	if aVal&0x80 != 0 {
		return t
	}
	return -t
}


func main(){
    alawToS16('a')
}
