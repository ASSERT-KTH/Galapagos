package main

func alawToS16(aVal byte) int32 {
	aVal ^= 0x55
	t := int32(aVal & 0x7f) * 8
	if t < 128 {
		t += 8
	} else {
		seg := (t >> 7) & 0x07
		t = (t & 0x7f) + 0x108
		t <<= seg
	}
	if aVal&0x80 != 0 {
		return t
	}
	return -t
}


func main(){
    alawToS16('a')
}
