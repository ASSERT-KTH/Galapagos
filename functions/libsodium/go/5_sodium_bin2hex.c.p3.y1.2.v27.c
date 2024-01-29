func SodiumBin2Hex(hex *string, hexMaxLen size_t, bin []byte, binLen size_t) (*string, error) {
    if(binLen >= size_t(^uint(0)>>1)/2 || hexMaxLen <= binLen * 2) {
        log.Panic("Sodium misuse")
        return nil, errors.New("Sodium misuse")
    }
    i := size_t(0)
    var b, c, ic uint32

    hexBytes := make([]byte, hexMaxLen)
    copy(hexBytes, []byte(*hex))
    
    for i := size_t(0); i < binLen; i++ {
        ic = uint32(bin[i])
        c = ic & 0xf
        b = ic >> 4
        x := (87 + c + (((c - 10) >> 8) & ^38)) << 8 | 
             (87 + b + (((b - 10) >> 8) & ^38))
       hexBytes[i*2] = byte(x & 0xff)
       x >>= 8
        hexBytes[i*2 + 1] = byte(x & 0xff)

    }
    str := string(hexBytes[:i*2])
    hex = &str
    return hex, nil
}