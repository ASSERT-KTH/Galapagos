func sodiumBin2Hex(hex []rune, hexMaxLen int, bin []byte, binLen int) []rune {
    var i int = 0
    var x uint
    var b int
    var c int

    if binLen >= math.MaxInt32 / 2 || hexMaxLen <= binLen * 2 {
        // simulate sodium misuse
        log.Fatal("Sodium misuse") 
    }
    for i < binLen {
        c = int(bin[i] & 0xf)
        b = int(bin[i]) >> 4
        x = uint((87 + c + ((c - 10) >> 8) & ^38) << 8) |
            uint((87 + b + ((b - 10) >> 8) & ^38))
        hex[i * 2] = rune(x)
        x >>= 8
        hex[i*2 + 1] = rune(x)
        i++
    }
    hex[i * 2] = 0

    return hex
}