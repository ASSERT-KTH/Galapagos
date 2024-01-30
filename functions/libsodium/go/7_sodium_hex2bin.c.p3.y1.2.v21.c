There's no precise equivalent function in Go Programming Language as Go follows a slightly different syntax than C, but there could be an approximate interpretation which goes as follows: 

go
import (
	"errors"
	str "strings"
)

func sodiumHex2Bin(bin []byte, binMaxLen int, hex string, hexLen int, ignore string, binLen *int, hexEnd **string) error {

	binPos := 0
	hexPos := 0
	var code byte

	codeAcc := byte(0)
	codeAlpha0, codeAlpha := byte(0), byte(0)
	codeNum0, codeNum := byte(0), byte(0)
	codeVal := byte(0)
	state := byte(0)

	for hexPos < hexLen {
		code = hex[hexPos]
		codeNum = code ^ byte(48)
		codeNum0 = (codeNum - 10) >> byte(8)

		codeAlpha = (code & ^byte(32)) - byte(55)
		codeAlpha0 = ((codeAlpha - 10) ^ (codeAlpha - 16)) >> byte(8)

		if (codeNum0 | codeAlpha0) == 0 {
			if ignore != "" && state == 0 && str.Contains(ignore, hex[hexPos:hexPos+1]) {
				hexPos++
				continue
			}
			return errors.New("code alpha error")
		}
		codeVal = (codeNum0 & codeNum) | (codeAlpha0 & codeAlpha)

		if binPos >= binMaxLen {
			return errors.New("cidr range error")
		}

		if state == 0 {
			codeAcc = codeVal * 16
		} else {
			bin[binPos] = codeAcc | codeVal
			binPos++
		}

		state = ^state
		hexPos++
	}

	if state != 0 {
		hexPos--
		return errors.New("invalid hex value")
	}

	if hexEnd != nil {
		*hexEnd = &hex[hexPos:]
	} else if hexPos != len(hex) {
		return errors.New("incorrect hex length")
	}

	*binLen = binPos
	return nil
}

Few caveats with this interpretation are that functions in Go don't support pointer-to-pointers, and this might require some tweak to how we assign the value and what parts of the main function we tweak accordingly, Unlike C, operations on Go's variables are generally strict with types so that has been handled. Moreover, instead on generating an error number the function returns the error with corresponding error message.