package main

func b64CharToByte(c int32) uint32 {
	if c >= 65 && c <= 90 {
		return uint32(c - 65)
	}
	if c >= 97 && c <= 122 {
		return uint32(c - 97 + 26)
	}
	if c >= 48 && c <= 57 {
		return uint32(c - 48 + 52)
	}
	if c == 43 {
		return 62
	}
	if c == 47 {
		return 63
	}
	return 0
}


func main(){
    b64CharToByte(0)
}
