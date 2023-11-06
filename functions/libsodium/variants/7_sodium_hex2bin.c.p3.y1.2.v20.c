Here's an equivalent implementation of the above `sodium_hex2bin` function in Go.

go
import (
	"errors"
	"strings"
)

func sodium_hex2bin(bin []byte, bin_maxlen uint, hex string, hex_len uint, ignore string, bin_len *uint, hex_end *uint) int {
	var bin_pos, hex_pos uint = 0, 0
	var ret int = 0
	var c, c_acc byte
	var c_alpha0, c_alpha byte
	var c_num0, c_num byte
	var c_val byte
	var state byte = 0
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
			errno = errors.New("ERANGE")
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
	if state != 0{
		hex_pos--
		errno = errors.New("EINVAL")
		ret = -1
	}
	if ret != 0 {
		bin_pos = 0
	}
	if hex_end != nil {
		*hex_end = &hex[hex_pos]
	} else if hex_pos != hex_len {
		errno = errors.New("EINVAL")
		ret = -1
	}
	if bin_len != nil {
		*bin_len = bin_pos
	}
	return ret
}

Please note that `errno` in C translates to error in Go, and errors in Go are values, so you must have any error variable to receive it. Also the Go equivalent would return (*uint, error) instead of int, but equivalent errno messages were added as shown above in enigmatic errors to fit the scenario you requested.