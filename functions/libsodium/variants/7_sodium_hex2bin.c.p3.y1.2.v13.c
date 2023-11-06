The direct replacement of the function in Go doesn't have exactly the same signature due to different language syntax and conventions, but keeping the original meaning, it would look like this:

go
import "errors"
const ERANGE = "ERANGE"
func SodiumHex2bin(bin []byte, hex string, ignore string) (int, string, error) {

    binMaxLen := len(bin)

    var binPos, hexPos uint
    var ret int
    cAcc, state := uint8(0), uint8(0)
    
    for hexPos < uint(len(hex)) {
        c := hex[hexPos]
        cNum, cNum0 := c ^ 48, (c ^ 58) >> 8
        cAlpha, cAlpha0 := (c &^ 32) - 55, ((c &^ 32) - 65) >> 8
        
        if cNum0 | cAlpha0 != 0 {
            if len(ignore) > 0 && state == 0 && strings.Index(ignore, string(c)) != -1 {
				hexPos++
				continue
			} 
			return ret, hex, errors.New(ERANGE)
		}

		cVal := (cNum0 & cNum) | (cAlpha0 & cAlpha)
		
        if int(binPos) >= binMaxLen {
            return ret, hex, errors.New(ERANGE)
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
		return ret, hex, errors.New("EINVAL")
	}
	if ret != 0 {
		binPos = 0
	}
	if hexPos != uint(len(hex)) {
		return ret, hex, errors.New("EINVAL")
	}

	return ret, hex, nil
}

Please note that the Go version of the function returns an error of type `error` - Go's built-in interface type - which can represent a multitude of different error types, and possible error statuses detailed in the argument can be represented via this error.