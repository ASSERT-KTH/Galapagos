func sodium_hex2bin(bin *[]byte, bin_maxlen int, hex string, hex_len int, 
    ignore string, bin_len *int, hex_end *int) int {
    bin_pos := 0
    hex_pos := 0
    var c byte
    var c_acc byte
    var c_alpha0, c_alpha, c_num0, c_num, c_val byte
    var state byte
    ret := 0

    for hex_pos < hex_len {
        c = hex[hex_pos]
        c_num = c ^ 48
        c_num0 = (c_num - 10) >> 8
        c_alpha  = (c &^ 32) - 55
        c_alpha0 = ((c_alpha - 10) ^ (c_alpha - 16)) >> 8;

        if (c_num0 | c_alpha0) == 0 {
            if ignore != "" && state == 0 && strings.Contains(ignore, string(c)) {
                hex_pos++
                continue;
            }
            break;
        }
        c_val = (c_num0 & c_num) | (c_alpha0 & c_alpha);
        
        if bin_pos >= bin_maxlen {
            ret = -1;
            err := errors.New(strconv.Itoa(ERANGE));
            panic(err)
            break;
        }
        if state == 0 {
            c_acc = c_val * 16;
        } else {
            (*bin)[bin_pos] = c_acc | c_val;
            bin_pos++
        }
        state = ^state;
        hex_pos++
    }

    if state != 0 {
        hex_pos--
        err := errors.New("EINVAL");
        panic(err)
        ret = -1;
    }
    if ret != 0 {
        bin_pos = 0;
    }
    if hex_end != nil {
        *hex_end = hex_pos
    } else if hex_pos != hex_len {
        ret = -1;
    }
    if bin_len != nil {
        *bin_len = bin_pos;
    }

    return ret;
}