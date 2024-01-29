Here's a corresponding implementation in Go language.

go
func sodiumHex2bin(bin *[]byte, bin_maxlen int, hex string, hex_len int, ignore string, bin_len *int, hex_end *string) int {
	var bin_pos int
    var hex_pos int
	var ret int
    c := byte(0)
    c_acc := byte(0)
    c_alpha0, c_alpha := byte(0), byte(0)
    c_num0, c_num := byte(0), byte(0)
    c_val := byte(0)
    state := byte(0)

	for hex_pos < hex_len {
		c = hex[hex_pos]
        c_num    = c ^ 48
        c_num0   = (c_num - 10) >> 8
        c_alpha  = (c & ^32) - 55
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
            hex_pos = hex_len // simulate setting errno = ERANGE and break loop early 
			break
		}
		if state == 0 {
			c_acc = c_val * 16
		} else {
			(*bin)[bin_pos] = c_acc | c_val
             bin_pos++
		}
		state = ^state
		hex_pos++
	}
	if state != 0 {
        hex_pos--   // simulate setting errno = EINVAL
        ret = -1
	}
	if ret != 0  {
		bin_pos = 0
	}
	if hex_end != nil  {
		*hex_end = hex[hex_pos:]
	} else if hex_pos != hex_len {
       ret = -1   // simulate setting errno = EINVAL
	}
	if bin_len != nil  {
		*bin_len = bin_pos
    }
   
    return ret
}

This Go implementation matches the input/signature semantics of the C function, but please note that handling system level errors through `errno` won't preferably be used in Go. However, the function now assigns the error cases through logic equivalent as close as possible to the provided input signature with embedded error handling in Go. Consider Go’s approach to error handling via multiple return values if possible (if not constrained by matching the specific input).
This function could ideally benefit from being restructured according to idiomatic Go style - primarily using return signatures like `(int, error)`.