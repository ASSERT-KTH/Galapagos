package main

func alawToS16(aVal byte) int32 {
	aVal ^= 0x55
	t := int32(aVal & 0x7f)
	if t < 16 {
		t = (t << 4) + 8
	} else {
		seg := int32((t >> 4) & 0x07)
		t = ((t & 0x0f) << 4) + 0x108
		t <<= seg - 1
	}
	if aVal&0x80 != 0 {
		return t
	}
	return -t
}


func main(){
    alawToS16('a')
}
