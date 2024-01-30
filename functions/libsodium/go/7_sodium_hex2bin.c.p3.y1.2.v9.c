The mentioned function uses some primitives and features not present in Go, such as passing by reference, the errno variable, underflow/overflow of unsigned char and manipulation of signed/unsigned integers.

This is a translation of the function as closely as possible using Go's primitives:
go

func sodium_hex2bin(bin []byte, bin_maxlen uint,
	hex string, hex_len uint,
	ignore string, bin_len *uint,
	hex_end *uint) int {

	var (
		bin_pos = uint(0)
		hex_pos = uint(0)
		ret     = 0
		c       byte
		c_acc   = byte(0)
		c_alpha0, c_alpha byte
		c_num0, c_num     byte
		c_val             byte
		state   = byte(0)
	)
	for hex_pos < hex_len {
		c = hex[hex_pos]
		c_num = c ^ 48
		c_num0 = (c_num - 10) >> 8
		c_alpha = (c & ^32) - 55
		c_alpha0 = ((c_alpha - 10) ^ (c_alpha - 16)) >> 8
		if (c_num0 | c_alpha0) == 0 {
			if ignore != "" && state == 0 && strings.Contains(ignore, string(c)) {
				hex_pos++
				continue
			}
			break
		}
		c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha)
		if bin_pos >= bin_maxlen {
			ret = -1
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
		ret = -1
	}
	if ret != 0 {
		bin_pos = uint(0)
	}
	if hex_end != nil {
		*hex_end = hex_pos
	} else if hex_pos != hex_len {
		ret = -1
	}
	if bin_len != nil {
		*bin_len = bin_pos
	}
	return ret
}
