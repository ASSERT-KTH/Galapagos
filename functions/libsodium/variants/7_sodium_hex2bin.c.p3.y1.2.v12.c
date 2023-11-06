golang
package main

import (
	"errors"
)

const (
	lowerHexDigitByteStart                             = 48
	upperHexDigitByteStartDividedByTwo                 = 55
	firstByteOfIndicatingACharacterIsALowerHexDigit    = 10
	secondByteOfIndicatingACharacterIsALowerOrUpperHex = 10
	sixteenthByteOfIndicatingACharacterIsNotAnUpperHex = 16
)

func sodiumHex2bin(bin []byte, bin_maxlen int, hex []byte, hex_len int, ignore []byte, bin_len *int, hex_end *[]byte) (int, error) {
	bin_pos := 0
	hex_pos := 0
	ret := 0
	var c byte
	c_acc := byte(0)
	var c_alpha0, c_alpha byte
	var c_num0, c_num byte
	var c_val byte
	state := byte(0)

	for hex_pos < hex_len {
		c = hex[hex_pos]
		c_num = c ^ lowerHexDigitByteStart
		c_num0 = (c_num - firstByteOfIndicatingACharacterIsALowerHexDigit) >> upperByteIndicatorDivisionNecessityCoefficient