Here is how you might implement the, essentially equivalent, function in Go:

Go
func sodiumHex2bin(bin []byte, binMaxlen int, hex string, hexLen int, ignore string, 
                   binLen *int, hexEnd *int) int {
    binPos := 0
    hexPos := 0
    ret := 0
    var c byte
    cAcc := byte(0)
    var cAlpha0, cAlpha byte
    var cNum0, cNum byte
    var cVal byte
    state := byte(0)
    var e error

    for hexPos < hexLen {
        c = byte(hex[hexPos])
        cNum = c^ 48
        cNum0 = (cNum - 10) >> 8
        cAlpha = (c &^ 32) - 55
        cAlpha0 = ((cAlpha - 10) ^ (cAlpha - 16)) >> 8
        if (cNum0 | cAlpha0) == 0 {
            if len(ignore) > 0 && state == 0 && strings.ContainsRune(ignore, rune(c)) {
                hexPos++
                continue
            }
            break
        }
        cVal = (cNum0 & cNum) | (cAlpha0 & cAlpha)
        if binPos >= binMaxlen {
            ret = -1
            e = syscall.ERANGE
            break
        }
        if state == 0 {
            cAcc = cVal * 16
        } else {
            bin[binPos] = cAcc | cVal
            binPos++
        }
        state = ^state
        hexPos++
    }
    if state != 0 {
        hexPos--
        e = syscall.EINVAL
        ret = -1
    }
    if ret != 0 {
        binPos = 0
    }
    if hexEnd != nil {
        *hexEnd = hexPos
    } else if hexPos != hexLen {
        e = syscall.EINVAL
        ret = -1
    }
    if binLen != nil {
        *binLen = binPos
    }
    return ret
}

While Go does not have direct equivalents to `errno` and `unsigned char`, much of the original algorithm and cyclical testing is preserved, substituting the C idioms for their closest Go equivalents. Strict checking for Edge Cases as was nicely taken care of in C, such as in `if ((c_num0 | c_alpha0) == 0U)`, doesn't always translate directly and could be enhanced if application details were more specified.