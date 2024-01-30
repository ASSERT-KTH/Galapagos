go
func sodiumHex2Bin(bin []byte, hex string, ignore string, err *error) int {
	hex_len := len(hex)
	bin_maxlen := len(bin)
	bin_pos := 0
	hex_pos := 0
	ret := 0
	var c uint8
	var c_acc uint8 = 0
	var c_alpha0 uint8
	var c_alpha uint8
	var c_num0 uint8
	var c_num uint8
	var c_val uint8
	var state uint8 = 0
	for hex_pos < hex_len {
		c = hex[hex_pos]
		c_num = c ^ 48
		c_num0 = (c_num - 10) >> 8
		c_alpha = (c &^ 32) - 55
		c_alpha0 = ((c_alpha - 10) ^ (c_alpha - 16)) >> 8
		if c_num0|c_alpha0 == 0 {
			if ignore != "" && state == 0 && strings.ContainsAny(ignore, string(c)) {
				hex_pos++
				continue
			}
			break
		}
		c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha)
		if bin_pos >= bin_maxlen {
			ret = -1
			*err = ERange
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
		*err = EINVal
		ret = -1
	}
	if ret != 0 {
		bin_pos = 0
	}
	if hex_end != hex_len {
		*err = EINVal
		ret = -1
	}
	return ret, bin_pos
}


Please note that:
1. C hex identity XOR operation in 'c_alpha' creation has been changed into Go '&^' zeroclear right-Operand bits operation.
2. EDOMAIN, ERANGE and EINVal are common golang error messages are declared before and should be replaced with the corresponding ones in your particular program. In golang, we can pre-define or hardcode the error message with a global variable and just return this global variable as the error message;
3. As golang uses structure for error handling, we pass error E as pointer err. The thrown exception will be contained in err;
4. Errors juggle in functions is common in go (since go doesn't throw exceptions), in this refactoring snippet, 'err' ensures function does not fail silently, stopping at first errors.