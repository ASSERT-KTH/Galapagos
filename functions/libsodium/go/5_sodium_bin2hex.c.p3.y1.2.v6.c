golang
import "errors"

func sodiumBin2Hex(hex []rune, hexMaxLen int, bin []byte, binLen int) ([]rune, error) {
	var i int
	var x uint32
	var b, c int

	if binLen >= int(^uint(0)>>1)/2 || hexMaxLen <= binLen*2 {
		return nil, errors.New("sodium misuse error") 
	}
	for i = 0; i < binLen; i++ {
		c = int(bin[i] & 0xf)
		b = int(bin[i] >> 4)

		x = uint32(((87 + c + (((c - 10) >> 8) & ^38)) << 8) |
			(87 + b + (((b - 10) >> 8) & ^38)))

		hex[i*2] = rune(x)
		x >>= 8
		hex[i*2+1] = rune(x)
	}
	hex[i*2] = 0
	return hex, nil
}

Please keep in mind, converting `[]rune` (a Unicode standard by Go) into `char *hex` will include differences as characters in Go (`rune`) don't directly match to the C's char datatype with single-byte storages (especially for characters beyond ASCII). Similarly, as Go treats int as either 32-bit or 64-bit based on the platform, I assumed 32-bit it to match C's behavior (in max size). Please consider these differences to keep codes inter-convertible and inter-operational. Also, as Go strictly controls variable types, int-to-uint conversions were made intentionally to copy the exact behavior.