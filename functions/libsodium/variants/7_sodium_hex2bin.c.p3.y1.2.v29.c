It's not feasible to directly translate C to Go while preserving the exact function signature of your given C function because Go does not support pointer argument. Below I approximate a translation making the necessary changes to fit reasonable Go programming customs.

However, what should to be achieved by this function is to convert hexadecimal formatted text to binary, skipping characters in ignore string optionally.

go
package main

import (
	"errors"
	"strings"
)

func sodiumHex2Bin(bin []byte, binMaxlen uint, hex string, hexLen uint, ignore string, binLen *uint, hexEnd *int) error {
	binPos := uint(0)
	hexPos := uint(0)
	c, cAcc, state := byte(0), byte(0), byte(0)

	for hexPos < hexLen {
		c = hex[hexPos]
		cNum := c ^ 48
		cNum0 := (cNum - 10) >> 8
		cAlpha := (c & ~32) - 55
		cAlpha0 := ((cAlpha - 10) ^ (cAlpha - 16)) >> 8

		if (cNum0 | cAlpha0) == 0 {
			if ignore != "" && state == 0 && strings.Contains(ignore, string(c)) {
				hexPos++
				continue
			}
			break
		}
		cVal := (cNum0 & cNum) | (cAlpha0 & cAlpha)
		if binPos >= binMaxlen {
			return errors.New("destination buffer is too small")
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
		*hexEnd = int(hexPos)
	} else if hexPos != hexLen {
		return errors.New("invalid hex string")
	}
	if binLen != nil {
		*binLen = binPos
	}
	return nil
}

Please revise error and input handling to match your exact requirements. This code presently checks formatted binary would exceed available space in given 'bin' space and checks for given hex string to respect common hexadecimal formatting rules disregarding case variability.