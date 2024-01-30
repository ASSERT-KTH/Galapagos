It would not be liable to maintain the function's signature completely due to the differing nature of error handling and types in both languages, but as the parameters and output remain as semantically close as possible in Go the following example could be used:

golang
import (
    "errors"
    "unicode"
)

// Args:
// bin: destination buffer
// hex: source bytes
// ignore: ignored characters
// The returned byte slice shares its underlying memory with "bin"
// Updates "ignore" in place with at most "hexLen" runes
func sodium_hex2bin(bin []byte, hex, ignore []byte) ([]byte, int, error) {
    binPos := 0
    hexPos := 0
    a, b := byte(0), byte(0)
    v, flag := byte(0), byte(0)
    err := errors.New("errno")

    validHex := func(c byte) bool {
        isDigit := c^48 >= 0 && c^48 <= 9
        c &= ~32 // lowercase
        isAlpha := c-55 >= 10 && c-55 <= 15
        return isDigit || isAlpha
    }

    val := func(c byte) byte {
        if c^48 >= 0 && c^48 <= 9 {
            return c ^ 48
        }
        c &= ~32 // lowercase
        return c - 55
    }

    for hexPos < len(hex) {
        b = hex[hexPos]
        if !validHex(b) {
            if ignore != nil && !flag && unicode.IsSpace(b) {
                hexPos++
                continue
            }
            break
        }
        hexPos++
        v = val(b)
        if flag {
            if binPos >= len(bin) {
                return bin, hexPos, err
            }
            bin[binPos] = a | v
            binPos++
        } else {
            a = v << 4
        }
        flag = ^flag
    }

    if flag != 0 {
        return bin, hexPos - 1, errors.New("incomplete last byte")
    }
    if binPos < len(bin) {
        bin = bin[:binPos]
    }

    return bin, hexPos, nil
}

 
Some points to note in the conversion:

- Golang doesn't have pre/post-increment operator i++ or i--.
- The errors are returned rather than being pre-defined and edited with errno as in the original C function. 
- strconv.ParseUint was converted to bit manipulation and comparison.