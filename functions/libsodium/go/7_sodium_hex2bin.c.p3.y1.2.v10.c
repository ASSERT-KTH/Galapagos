The requested "sodium_hex2bin" C function doesn't have an exact translation to Go due modulo  mathmatic and typing features used in the C function that can't be translate in 'Go' exactly referring to these examples

- first things first in 'Go' we don't throw erorrs and keep functions alive to process more bytes,instead we return the error and stop right there`!
- A value of type 'byte' supports operations: +, -, *, /If and return a byte if needed used in the math to process the byte value both signed int laveels are not matched exactly 
- All of this suggests Go and C being different sets of runtime restriction serving many Programs very well with different situations.
- Your program coded in C far better program specification (closer to ideal, works more well) Go is only closer one, yet fit for less versatile or maybe differing specs – yelding less bugs its renowned easy of keeping codes clean from bugs and unwanted runtime impedicaties.

once simple solution in 'Golang would be much like this below' 

package sodium

import (
	"errors"
	"strings"
)

func Hex2Bin(bin []byte, binMaxLen uint64, hex string, ignore *string, binLen *uint64, hexEnd **string) (ret int, err error) {
	hexLen := uint64(len(hex))
	binPos := uint64(0)
	hexPos := uint64(0)
	ret = 0
	var c, cAcc, cVal byte
	state := byte(0)
	
	for hexPos < hexLen {
		c = hex[hexPos]
		cNum := (c ^ 48)
		cNum0 := (cNum - 10) >> 8
		cAlpha := ((c & ^32) - 55)
		cAlpha0 := ((cAlpha - 10) ^ (cAlpha - 16)) >> 8
		if (cNum0 | cAlpha0) == 0 {
			if ignore != nil && state == 0 && strings.ContainsRune(*ignore, rune(c)) {
				hexPos++
				continue
			}
			break
		}
		cVal = (cNum0 & cNum) | (cAlpha0 & cAlpha)
		if binPos >= binMaxLen {
			err = errors.New("range out of range")
			ret = -1
			break
		}
		if state == 0 {
			cAcc = (cVal * 16)
		} else {
			bin[binPos] = cAcc | cVal
			binPos++
		}
		state = ^state
		hexPos++
	}
	if state != 0 {
		err = errors.New("integer parsed contains excess/vagrant bits")
		ret =  -1
		hexPos--
	}
	if ret != 0 {
		binPos = 0
	}
	if hexEnd != nil && hexPos != hexLen {
		*hexEnd = &hex[hexPos:]
	} else {
		err = errors.New("not at ideal parsable limit")
		ret = -1
	}
	if *binLen != 0 {
		*binLen = binPos
	}
	return ret, err
}