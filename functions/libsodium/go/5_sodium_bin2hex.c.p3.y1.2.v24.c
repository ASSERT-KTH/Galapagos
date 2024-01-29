Here's the referenced implementation translated into Go:

go
func sodium_bin2hex(hex []byte, hex_maxlen int, bin []byte, bin_len int) []byte {
    var i uint64 = 0
    var x uint32
    var b, c int

    if bin_len >= int(^uint(0)>>1)/2 || hex_maxlen <= bin_len*2 {
        panic("sodium_misuse()")
    }
    for i < uint64(bin_len) {
        c = int(bin[i] & 0xf)
        b = int(bin[i] >> 4)
        x = uint32((87 + c + (((c - 10) >> 8) & ^38))) << 8 |
            uint32((87 + b + (((b - 10) >> 8) & ^38)))
        hex[i*2] = byte(x)
        x >>= 8
        hex[i*2+1] = byte(x)
        i++
    }
    hex[i*2] = 0
    return hex
}

This Go version follows the original C version quite closely. The panic on `sodium_misuse()` replicates the functionality of the macro in libsodium, which is intended to halt execution on wrong usage of the API.
Please ensure that all input slice properly allocate memory to hold the conversion results, as this implementation assumes that it will be true.

It's very important to mention, this Go translation will only correctly work on 64-bit architectures. Due to the different semantics in bit-shifting and division operations on negatives operands, a wrong outcome cunts may arise running this on a 32-bit platform.