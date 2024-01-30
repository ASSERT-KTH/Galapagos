Here is the function implemented in Go:

go
import (
    "errors"
    "strings"
)

func sodium_hex2bin(bin []byte, bin_maxlen int,
    hex string, hex_len int,
    ignore string, bin_len *int,
    hex_end *string) error {

    bin_pos := 0
    hex_pos := 0
    var c byte
    var c_acc byte
    var c_alpha0 byte
    var c_alpha byte
    var c_num0 byte
    var c_num byte
    var c_val byte
    state := byte(0)

    for hex_pos < hex_len {
        c = byte(hex[hex_pos])
        c_num = c ^ 48
        c_num0 = (c_num - 10) >> 8
        c_alpha = (c & ^32) - 55
        c_alpha0 = ((c_alpha - 10) ^ (c_alpha - 16)) >> 8
        if c_num0 | c_alpha0 == 0 {
            if ignore != "" && state == 0 && strings.ContainsRune(ignore, rune(c)) {
                hex_pos++
                continue
            }
            return errors.New("EINVAL")
        }
        c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha)
        if bin_pos >= bin_maxlen {
            return errors.New("ERANGE")
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
        return errors.New("EINVAL")
    }

    if hex_end != nil {
        *hex_end = hex[hex_pos:]
    } else if hex_pos != hex_len {
        return errors.New("EINVAL")
    }
    if bin_len != nil {
        *bin_len = bin_pos
    }
    return nil
}


Note: Go drives from Go's error handling idioms and utilizes the built-in "errors" package. HRESULT values have been replaced with the preferred idiomatic Go error handling approach. Go also does not have an equivalent for directly setting "errno". Errors are returned instead of status codes and errno setting. Go uses slices, and they replace both C-style arrays and pointers to size_t representing lengths.