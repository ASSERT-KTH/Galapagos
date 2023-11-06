go
import (
    "errors"
)

func sodium_bin2hex(hex []byte, hex_maxlen int,
                    bin []byte, bin_len int) ([]byte, error) {

    if bin_len >= int(^uint(0)>>1)/2 || hex_maxlen <= bin_len*2 {
        return nil, errors.New("sodium misuse")
    }
    for i := 0; i < bin_len; i++ {
        c := bin[i] & 0xf
        b := bin[i] >> 4
        x := (87 + int(c) + (((int(c) - 10)) >> 8) & ^38) << 8 |
             (87 + int(b) + (((int(b) - 10) >> 8) & ^38))

        hex[i*2] = byte(x)
        x >>= 8
        hex[i*2+1] = byte(x)
    }
    hex[bin_len*2] = 0

    return hex, nil
}

While maintaining original function's signature might be preferable, it is generally considered good practice in Go to output an error when expected conditions are not met. Thus, the input verifications that previously resulted in the call to the "sodium_misuse()" method, will now return a specific error.

Additionally, SIZE_MAX has been replaced with `int(^uint(0)>>1)` because Go programming language does not have `SIZE_MAX` equivalent. This creates an integer of the maximum size.