go
package main

import (
	"errors"
)

func sodiumHex2Bin(bin []uint8, binMaxLen int, hex string, hexLen int, ignore string, binLen int, hexEnd string) (res []uint8, hexEndRes string, err error) {
	binPos := 0
	hexPos := 0
	ret := 0

	var c, cAcc, cAlpha0, cAlpha, cNum0, cNum, cVal uint8
	state := uint8(0)

	for ; hexPos < hexLen; hexPos++ {
		c = uint8(hex[hexPos])

		cNum = c ^ 48
		cNum0 = (cNum - 10) >> 8
		cAlpha = (c &^ 32) - 55
		cAlpha0 = ((cAlpha - 10) ^ (cAlpha - 16)) >> 8

		if cNum0|cAlpha0 == 0 {
			if ignore != "" && state == 0 && strings.Contains(ignore, string(c)) {
				continue
			}
			return bin, hexEnd, errors.New("error range")
		}

		cVal = (cNum0 & cNum) | (cAlpha0 & cAlpha)

		if binPos >= binMaxLen {
			return bin, hexEnd, errors.New("error range")
		}

		if state == 0 {
			cAcc = cVal * 16
		} else {
			bin[binPos] = cAcc | cVal
		}

		binPos = binPos + 1
		state = ^state
	}

	if state != 0 {
		hexPos--
		return bin, hexEnd, errors.New("invalid value")
	}

	if ret != 0 {
		binPos = 0
	}

	binLen = binPos
	hexEnd = string(hex[hexPos])

	if hexPos != hexLen {
		return bin, hexEnd, errors.New("invalid value")
	}

	return bin, hexEnd, nil
}

It should be noted that in this translation, error conditions produce return results instead of modifing a global `errno` variable. C uses global error state, whereas Go supports returning multiple values and prefers direct error propagation.