go
import "errors"

func sodiumHex2Bin(bin []byte, binMaxLen int,
	hexStr string, hexLen int,
	ignore *string, binLen *int,
	hexEnd **int) error {

	binPos := 0
	hexPos := 0
	cAcc := byte(0)
	cVal := byte(0)
	state := byte(0)

	for hexPos < hexLen {
		c := hexStr[hexPos]
		cNum := c ^ 48
		cNum0 := (cNum - 10) >> 8
		cAlpha := (c & ^32) - 55
		cAlpha0 := ((cAlpha - 10) ^ (cAlpha - 16)) >> 8

		if (cNum0 | cAlpha0) == 0 {
			if ignore != nil && state == 0 && byteRuneExist(*ignore, rune(c)) {
				hexPos++
				continue
			}
			return errors.New("invalid hex string")
		}

		cVal = (cNum0 & cNum) | (cAlpha0 & cAlpha)

		if binPos >= binMaxLen {
			return errors.New("buffer too small")
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
		return errors.New("invalid hex string")
	}

	if hexEnd != nil {
		*hexEnd = &hexPos
	} else if hexPos != hexLen {
		return errors.New("invalid hex string")
	}

	if binLen != nil {
		*binLen = binPos
	}

	return nil
}

// checks if the rune exist in a string
func byteRuneExist(str string, r rune) bool {
	for _, runeValue := range str {
		if runeValue == r {
			return true;
		}
	}
	return false;
}
