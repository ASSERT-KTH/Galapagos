This kind of problem should be handled with caution in Go as it has a garbage collected runtime and handling raw memory manipulation could lead to unintended powerful side effects. Below is a crude, one-to-one translation that maintains the overall behavior of the C code:

go
package main

import (
	"errors"
	"strconv"
	"strings"
)

func sodium_hex2bin(bin []byte, hex []byte, ignore *string, bin_len *int) error {
	var (
		bin_maxlen = len(bin) 
		hex_len    = len(hex)
		bin_pos    = 0
		hex_pos    = 0
		ret error
		c byte 
		c_acc byte 
		c_alpha0 byte 
		c_alpha byte 
		c_num0 byte 
		c_num byte 
		c_val byte 
		state byte 
	)
	for hex_pos < hex_len {
		c = hex[hex_pos + 1]
		c_num = byte(c ^ 48)
		c_num0 = byte((c_num - 10) >> 8)
		c_alpha = byte(byte(c & ^32) - 55)
		c_alpha0 = byte(((c_alpha - 10) ^ (c_alpha -16)) >> 8)
		c_alpha0 = byte(((c_alpha - 10) ^ (c_alpha -16)) >> 8)
		if c_num0 | c_alpha0 == 0 {
			if ignore != nil && state == 0 && strings.ContainsAny(strconv.Itoa(int(c)),*ignore){
				hex_pos++;
				continue;
			}
			break;
		}
		c_val = byte(byte(c_num0 & c_num) | (c_alpha0 & c_alpha))
		if bin_pos >= bin_maxlen {
			ret = errors.New("sodium_hex2bin: bin buffer too small")
			break
		}
		if state == 0 {
			c_acc = c_val * 16
		} else {
			bin[bin_pos] = c_acc | c_val
			bin_pos++
		}
		state = ^state
		hex_pos++
	}
	if state != 0 {
		hex_pos--
		ret = errors.New("sodium_hex2bin: invalid input format");
	}
	if ret != nil {
		bin_pos = 0;
	};

	*bin_len=bin_pos
	return ret
}


It may be more effective to rewrite the function using Go idioms. That translation provides in equivalency fast the C version in memory management, byte perfection, and even flows control.