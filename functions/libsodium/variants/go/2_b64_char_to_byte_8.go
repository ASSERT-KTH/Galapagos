package main

func b64CharToByte(c int32) uint32 {
	const (
		UpperA      = 'A'
		UpperZ      = 'Z'
		LowerA      = 'a'
		LowerZ      = 'z'
		Num0        = '0'
		Num9        = '9'
		PlusSign    = '+'
		Slash       = '/'
		Base64Plus  = 62
		Base64Slash = 63
	)

	switch {
	case UpperA <= c && c <= UpperZ:
		return uint32(c - UpperA)
	case LowerA <= c && c <= LowerZ:
		return uint32(c - LowerA + 26)
	case Num0 <= c && c <= Num9:
		return uint32(c - Num0 + 52)
	case c == PlusSign:
		return Base64Plus
	case c == Slash:
		return Base64Slash
	default:
		return 0
	}
}


func main(){
    b64CharToByte(0)
}
