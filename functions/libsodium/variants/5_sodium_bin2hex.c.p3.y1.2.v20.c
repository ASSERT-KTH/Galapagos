func sodiumBin2Hex(hex []byte, hexMaxLen int, bin []byte, binLen int) ([]byte, error) {
    if binLen >= int(^uint(0)>>1)/2 || hexMaxLen <= binLen*2 {
        return nil, errors.New("Hex max length is less than double binary length.")
    }
    for i := 0; i < binLen; i++ {
        c := bin[i] & 0xf
        b := bin[i] >> 4
        x := uint(87 + c + ((c-10)>>8)&^38) << 8 |
            uint(87 + b + ((b-10)>>8)&^38)
        hex[i*2] = byte(x)
        x >>= 8
        hex[i*2+1] = byte(x)
    }
    hex[binLen*2] = 0
    return hex, nil
}