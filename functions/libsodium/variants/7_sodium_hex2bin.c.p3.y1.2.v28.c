Translation of the provided C code to Go programming language would look like this:
go
func sodium_hex2bin(bin []byte, bin_maxlen int, hex string, hex_len int, ignore string, bin_len *int, hex_end *string) int {
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
        c_num = c ^ 48
        c_num0 = (c_num - 10) >> 8
        c_alpha = (c & ^32) - 55
        c_alpha0 = ((c_alpha - 10) ^ (c_alpha - 16)) >> 8
        if c_num0|c_alpha0 == 0 {
            if ignore != "" && state == 0 && strings.ContainsRune(ignore, rune(c)) {
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
        bin_pos = 0
    }
    if hex_end != nil {
        *hex_end = hex[hex_pos:]
    } else if hex_pos != hex_len {
        ret = -1
    }
    if bin_len != nil {
        *bin_len = bin_pos
    }
    return ret
}


Here, `rune()` is equivalent to `char` datatype in C. The string indexing, unlike byte (or char) array indexing in C, returns the `rune` Unicode code-point (i.e., a character), from the string in Go, hence we use `strings.ContainsRune()` function instead of `strchr()` function to check whether a character exists in a string. Moreover, we assume `int` represents 32-bits length integer as `size_t` in C typically is 32-bits in 32-bits platforms and 64-bits in 64-bits platforms.