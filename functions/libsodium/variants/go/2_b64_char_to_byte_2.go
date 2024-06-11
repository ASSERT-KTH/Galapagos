package main

func b64CharToByte(c int32) uint32 {
	switch {
	case c >= 'A' && c <= 'Z':
		return uint32(c - 'A')
	case c >= 'a' && c <= 'z':
		return uint32(c - 'a' + 26)
	case c >= '0' && c <= '9':
		return uint32(c - '0' + 52)
	case c == '+':
		return 62
	case c == '/':
		return 63
	default:
		return 0
	}
}


func main(){
    b64CharToByte(0)
}
