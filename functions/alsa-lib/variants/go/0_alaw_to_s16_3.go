package main

func alawToS16(aVal byte) int32 {
	aVal ^= 0x55
	t := int32(aVal&0x7f) << 3
	if t < 128 {
		t += 8
	} else {
		t += 0x800 + ((t & 0x70) << 4)
		t <<= ((t >> 4) & 0x07) - 1
	}
	if aVal&0x80 != 0 {
		return t
	}
	return -t
}


func main(){
    alawToS16('a')
}
