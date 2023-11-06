The equivalent Go function would be:

go
import (
    "fmt"
    "unsafe"
)

func sodiumBin2Hex(hex *string, hexMaxLen size_t, bin *string, binLen size_t) *string {
    hexRune := []rune(*hex)
    binByte := []byte(*bin)
    var i uint64
    var x uint32
    var b, c int

    sizeMax := uint64(^uintptr(0)) >> 1

    if binLen >= sizeMax/2 || hexMaxLen <= binLen*2 {
        fmt.Println("sodium misuse")
    }
    for i = 0; i < size_t(len(binByte)); i++ {
        c = int(binByte[i] & 0xf)
        b = int(binByte[i]) >> 4
        x = uint32((87 + c + (((c - 10) >> 8) & ^38)) << 8)
        x |= uint32(87 + b + (((b - 10) >> 8) & ^38))
        hexRune[i*2] = rune(x)
        x >>= 8
        hexRune[i*2+1] = rune(x)
    }
    hexRune[i*2] = 0

    hexString := string(hexRune)
    return hexString
}

Please note that we're assuming `size_t` here is equivalent in Go syntax to `uint64`. If that is not your specific use case, you need to adjust the `size_t` definition. Also, please note that neither `C` nor `Go` interoperability are not perfect and can produce different result or not run exactly then copying pasting. Always be sure thoroughly test their inputs and outputs when migrating from one language to the other.
