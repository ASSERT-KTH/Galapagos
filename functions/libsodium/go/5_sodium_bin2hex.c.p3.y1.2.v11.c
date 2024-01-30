go
func sodium_bin2hex(hex_maxlen uint64, bin_len uint64, bin []byte) (hex []byte) {
    if bin_len >= math.MaxUint64/2 || hex_maxlen <= bin_len*2 {
        panic("sodium misuse")
    }
    hex = make([]byte, bin_len*2+1)
    for i := uint64(0); i < bin_len; i++ {
        c := bin[i] & 0xf
        b := bin[i] >> 4
        x := (byte)(87 + c + (((c - 10) >> 8) & ^38))<<8 |
            (byte)(87 + b + (((b - 10) >> 8) & ^38))
        hex[i*2] = x
        x >>= 8
        hex[i*2+1] = x
    }
    hex[bin_len*2] = 0
    return hex
}


Please note that the signature differs a bit from the input parameters C variant as in this Go variant we are receiving slice as Byte array and length can derived from the Byte itself "+len+" where it's a norm whereas both C variant doesn't use Byte or String they have Char where we need to share the length separately. Also if needed to share an output (String/Byte) from a Function in Go or any other language it should present it as return value instead placing it as Input parameter in function signature(that's is not a norm and creating ambiguity for implementation). As I didn't aware of actual syntax for function "sodium_misuse()" and treating its a generic function to handle exception where using "panic" in Go.