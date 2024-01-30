go
func sodiumHex2Bin(bin []uint8, binMaxLen int, hex []byte, hexLen int, ignore *string, binLen *int) (string, int) {

    var binPos, hexPos int
    var c, cAcc, cAlpha0, cAlpha, cNum0, cNum, cVal uint8
    var state uint8
    var ret int
    var hexEnd string
    state = 0

    ret = 0
	hexEnd = ""
    
    for hexPos < hexLen {

        c = uint8(hex[hexPos])
        cNum = c ^ 48
        cNum0 = (cNum - 10) >> 8
        cAlpha = (c &^ 32) - 55
        cAlpha0 = ((cAlpha - 10) ^ (cAlpha - 16 )) >> 8

        if (cNum0 | cAlpha0) == 0 {
            
            if (ignore != nil && state == 0 && strings.ContainsRune(*ignore, rune(c))) {
                hexPos++
                continue
            }
            break
        }
        cVal = (cNum0 & cNum) | (cAlpha0 & cAlpha)

        if binPos >= binMaxLen {
            ret = -1
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
        ret = -1
    }
    if ret != 0{
        binPos = 0
    } 
    
    if hexPos != hexLen {
        ret = -1
        hexEnd = string(hex[hexPos:])
    } 

    if binLen != nil {
        *binLen = binPos
    }
    return hexEnd, ret
}
