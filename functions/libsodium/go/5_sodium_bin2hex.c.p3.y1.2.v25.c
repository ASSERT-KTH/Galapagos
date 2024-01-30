Here is the equivalent function in Go:

go
func sodiumBin2Hex(hex []byte, hex_maxlen int, bin []byte, bin_len int) []byte {
	var i int = 0
	var x uint
	var b int
	var c int
	
	if bin_len >= int(^uint(0)>>1)/2 || hex_maxlen <= bin_len*2 {
		panic("sodium misuse")
	}
	
	for i = 0; i < bin_len; i++ {
		c = int(bin[i] & 0xf)
		b = int(bin[i] >> 4)
		x = uint((87 + c + (((c - 10) >> 8) & ^38))<<8) |
            uint((87 + b + (((b - 10) >> 8) & ^38)))
		hex[i*2] = byte(x)
		x >>= 8
		hex[i*2 + 1] = byte(x)
	}

	hex[i*2] = 0 

	return hex
}


Some explanations:
- I've replaced char * with [] byte. In Go, this is the usual way to handle buffer that might contain non-printable bytes.
- sizeof max calculations for a Go size_t equivalent have done because there is no size_t and SIZE_MAX in go.
- panic function is the idiomatic way to blow out in cases there you might return a error or errno value; there is no exceptions. The caller will have to handle or ignore this panic, depending how critical this is to overall program operation.
- ^uint(0)>>1 generates max int value that is in installed in default int value starting with 8bit installations to 32 ones
- There might be more limitations and steps in other types conversions cause currently Go is far more picky compare with C ones.
The function copies against direction from halfed bin_len places - basically inversed direction-
This function reads the data right once again, in mirror.