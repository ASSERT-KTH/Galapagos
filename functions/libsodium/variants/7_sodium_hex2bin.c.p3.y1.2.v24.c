Here is the Go version:

Go
import (
    "errors"
    "strings"
)

func sodiumHex2bin(bin []byte, binMaxLen int, hex string, hexLen int,
    ignore string, binLen []int, hexEnd *int) (ret int, err error) {
    hexEndPTR := 0
    binPos := 0
    hexPos := 0
    c := byte(0)
    cAcc := byte(0)
    cAlpha0, cAlpha := byte(0), byte(0)
    cNum0, cNum := byte(0), byte(0)
    cVal := byte(0)
    state := byte(0)

    for hexPos < hexLen {
        c = hex[hexPos]
        cNum = c ^ 48
        cNum0 = (cNum - 10) >> 8
        cAlpha = (c &^ 32) - 55
        cAlpha0 = ((cAlpha - 10) ^ (cAlpha - 16)) >> 8

        if (cNum0|cAlpha0) == 0 {
            if ignore != "" && state == 0 && strings.ContainsRune(ignore, rune(c)) {
                hexPos++
                continue
            }
            err = errors.New("invalid input")
	    return -1, err
        }
        cVal = (cNum0 & cNum) | (cAlpha0 & cAlpha)
        if binPos >= binMaxLen {
            err = errors.New("return value does not fit in the provided buffer")
	    return -1, err
        }
        if state == 0 {
            cAcc = cVal << 4
        } else {
            bin[binPos] = cAcc | cVal
            binPos++
        }
        state = ^state
        hexPos++
        hexEndPTR = hexPos
    }
    if state != 0 {
        hexPos--
        err = errors.New("only half of a byte found")
	return -1, err
    }
    if hexEndPTR != hexLen {
        err = errors.New("input is null")
	return -1, err
    }
    binLen = append(binLen,binPos)
    hexEnd = &hexEndPTR
    return 0 , nil
}

Two key changes in the remake: 1) Error handling was reinterpreted as an Go error. 2) 'bin' variable, 'binLen' and 'hexEnd' acceptance is turned for more simpler and ease of use. Caveats remaining - the entire portion will discard the remaining data if the required `binMaxLen` bytes are not required.