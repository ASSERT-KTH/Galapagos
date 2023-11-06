go
package main

import "errors"

func sodiumHex2Bin(bin []byte, binMaxLen int, hex []byte, hexLen int, ignore []byte, binLen *int, hexEnd *int) (int, error) {
    binPos := 0
    hexPos := 0
    ret := 0
    var c, cAcc, cAlpha0, cAlpha, cNum0, cNum, cVal byte
    state := byte(0)

    for hexPos < hexLen {
        c = hex[hexPos]
        cNum = c ^ 48
        cNum0 = (cNum - 10) >> 8
        cAlpha = (c &^ 32) - 55
        cAlpha0 = ((cAlpha - 10) ^ (cAlpha - 16)) >> 8

        if cNum0 | cAlpha0 == 0 {
            if ignore != nil && state == 0 && containsByte(ignore, c) {
                hexPos++
                continue
            }
            break
        }

        cVal = (cNum0 & cNum) | (cAlpha0 & cAlpha)

        if binPos >= binMaxLen {
            ret = -1
            return ret, errors.New("bin length overflows")
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
        ret = -1
        return ret, errors.New("invalid state")
    }

    *binLen = binPos
    *hexEnd = hexPos

    if ret != 0 {
        binPos = 0
    }

    if *hexEnd != hexLen {
        ret = -1
        return ret, errors.New("hex length Mismatch")
    }

    return ret, nil
}

func containsByte(b []byte, c byte) bool {
    for _, v := range b {
        if v == c {
            return true
        }
    }
    return false
}
