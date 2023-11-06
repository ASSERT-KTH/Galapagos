func sodiumHex2bin(bin *[1024]byte, binMaxlen int,
                   hex string, hexLen int,
                   ignore string, binLen *int,
                   hexEnd *string) int {

    var binPos  int = 0
    var hexPos  int = 0
    var ret     int = 0
    var c       byte
    var cAcc    byte = 0
    var cAlpha0 byte
    var cAlpha  byte
    var cNum0   byte
    var cNum    byte
    var cVal    byte
    var state   byte = 0

    for hexPos < hexLen {
        c       = hex[hexPos]
        cNum    = c ^ 48
        cNum0   = (cNum - 10) >> 8
        cAlpha  = (c & ^32) - 55
        cAlpha0 = ((cAlpha - 10) ^ (cAlpha - 16)) >> 8
        if cNum0 | cAlpha0 == 0 {
            if ignore != "" && state == 0 && strings.IndexByte(ignore, c) != -1 {
                hexPos++
                continue
            }
            break
        }
        cVal = (cNum0 & cNum) | (cAlpha0 & cAlpha)
        if binPos >= binMaxlen {
            ret = -1
            return ret
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
    }

    if ret != 0 {
        binPos = 0
    }

    if hexEnd != nil {
        *hexEnd = hex[hexPos:]
    } else if hexPos != hexLen {
        return -1
    }

    if binLen != nil {
        *binLen = binPos
    }

    return ret
}