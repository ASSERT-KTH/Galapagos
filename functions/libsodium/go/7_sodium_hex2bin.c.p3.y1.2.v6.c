Even Though an exact translation of the 'sodium_hex2bin' function from C to Go is not possible as there's no errno (UNIX error) directly supported by the Go language. However, here is a semantically equivalent version of 'sodium_hex2bin' function from C to Go.

go
import "errors"

func sodium_hex2bin(bin []byte, bin_maxlen int, hex string, hex_len int, ignore string, 
                bin_len *int, hex_end **string) error {
    bin_pos := 0
    hex_pos := 0
    var c byte
    var c_num byte
    var c_num0 byte
    var c_alpha byte
    var c_alpha0 byte
    var state byte
    c_acc := byte(0)
    temp := true

    for hex_pos < hex_len {
        c = hex[hex_pos]
        c_num = c ^ 48
        c_num0 = (c_num - 10) >> 8
        c_alpha = (c & ^32) - 55
        c_alpha0 = ((c_alpha - 10) ^ (c_alpha - 16)) >> 8

        if c_num0|c_alpha0 == 0 {
            if ignore != "" && state == 0 && contains(ignore, c) {
                hex_pos++
                continue
            }
        }
        c_val := (c_num & c_num0) | (c_alpha0 & c_alpha)

        if bin_pos >= bin_maxlen {
            return errors.New("range error")
        }
        
        if state == 0 {
            c_acc = c_val << 4
        } else {
            bin[bin_pos] = c_acc | c_val
            bin_pos++
        }
        
        state = ^state
        hex_pos++
    }
    
    if state != 0 {
        hex_pos--
        return errors.New("invalid argument error")
    }

    *bin_len = bin_pos
    if hex_end != nil {
        *hex_end = hex[hex_pos:]
    } else if hex_pos != hex_len {
        return errors.New("invalid argument error")
    }
    
    return nil
}

func contains(s string, r byte) bool {
    for _, c := range s {
        if byte(c) == r {
            return true
        }
    }
    return false
}

Note: the existence of helper function is due to the differences between the C standard functions and the ones provided by Go's standard library. Numerical values associated with "errno" fail gracefully. In creation of helper functions, this implementation creates more maintainable code, due deeper implementation. 

