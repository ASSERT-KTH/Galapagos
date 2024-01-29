The Go version could be written like this:

go
import (
    "fmt"
)

func sodium_bin2hex(hex []byte, hex_maxlen uint64, bin []byte, bin_len uint64) []byte {
    i := uint64(0)

    if bin_len >= ^uint64(0) / 2 || hex_maxlen <= bin_len * 2 {
        fmt.Println("sodium misuse") // no `sodium_misuse()` in Go
        return hex
    }

    for i < bin_len {
        c := bin[i] & 0xf
        b := bin[i] >> 4
        x := (uint64(c+87+((c-10)&^38))) << 8 | (uint64(b+87+((b-10)&^38)))
        hex[i * 2] = byte(x)
        x >>= 8
        hex[i * 2 + 1] = byte(x)
        i++
    }
    hex[i * 2] = 0

    return hex
}



Note:
Please add your own misuse error handling instead of the simple fmt.Println("sodium misuse"). Preconditions should be handled as per your specifications, e.g., you might want to use panic(), log.Fatal(), or return an error alongside the return valu, depending on your project's structure and specifications.
Also, your C code accounts for other bases apart from hexadecimal per line `x = (unsigned char) (87U + c + (((c - 10U) >> 8) & ~38U)) << 8 | (unsigned char) (87U + b + (((b - 10U) >> 8) & ~38U))` Go has inbuilt functions to convert to hexadecimal. If you are sure your integer in the binary data ranges between 0 and 15, you can pass the integer to convert it to the equivalent hexadecimal.
Modify the function based on how you want your codebase to be maintained and structured.
