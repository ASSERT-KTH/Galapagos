Here is a semantically equivalent version of the above C function, translated into Go.

go
func Sodium_hex2bin(bin []byte, binMaxlen int,
	hex string, hexLen int,
	ignore string, binLen *int,
	hexEnd *string) int {

	var binPos int = 0
	var hexPos int = 0
	var ret int = 0
	var c, cAcc, cAlpha0, cAlpha, cNum0, cNum, cVal byte
	var state byte = 0
	errno := errors.New("Generic error")

	for hexPos < hexLen {
		c = hex[hexPos]
		cNum = c ^ 48
		cNum0 = (cNum - 10) >> 8
		cAlpha = (c & ^32) - 55
		cAlpha0 = ((cAlpha - 10) ^ (cAlpha - 16)) >> 8
		if ((cNum0 | cAlpha0) == 0) {
			if ignore != "" && state == 0 && strings.ContainsRune(ignore, rune(c)) {
				hexPos++
				continue
			}
			break
		}
		cVal = (cNum0 & cNum) | (cAlpha0 & cAlpha)
		if binPos >= binMaxlen {
			ret = -1
			errno = errors.New("Given bin maximum length exceeded")
			break
		}
		if state == 0 {
			cAcc = cVal * 16
		} else {
			bin[binPos] = cAcc | cVal
			binPos++
		}
		state = ^state
		hexPos++
	}
	if state != 0 {
		hexPos--
		errno = errors.New("Invalid argument")
		ret = -1
	}
	if ret != 0 {
		binPos = 0
	}
	if hexEnd != nil {
		*hexEnd = hex[hexPos:]
	} else if hexPos != hexLen {
		errno = errors.New("Invalid argument")
		ret = -1
	}
	if binLen != nil {
		*binLen = binPos
	}
	return ret
}

 
Errors in Go are values and handled by multiple-value return and built-in error interface. Hence, errno incorporated like any error in Go.