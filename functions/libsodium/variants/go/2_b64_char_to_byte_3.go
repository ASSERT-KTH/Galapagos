package main

func b64CharToByte(c int32) uint32 {
	if 'A' <= c && c <= 'Z' {
		return uint32(c - 'A')
	}
	if 'a' <= c && c <= 'z' {
		return uint32(c - 'a' + 26)
	}
	if '0' <= c && c <= '9' {
		return uint32(c - '0' + 52)
	}
	if c == '+' {
		return 62
	}
	if c == '/' {
		return 63
	}
	return 0
}


func main(){
    b64CharToByte(0)
}
