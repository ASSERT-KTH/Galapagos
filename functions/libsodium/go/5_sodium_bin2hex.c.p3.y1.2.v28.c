The following portrays how the provided C function would look coded in Go:

go
import "errors"

func sodiumBin2Hex(hex []byte, bin []byte) ([]byte, error) {
    var hexMaxlen = len(hex)
    var binLen = len(bin)

    if binLen >= int(^uint(0)>>1)/2 || hexMaxlen <= binLen*2 {
        return nil, errors.New("Invalid input lengths")
    }

    for i := 0; i < binLen; i++ {
        c := bin[i] & 0xf;
        b := bin[i] >> 4;
        x := byte((87 + c + (((c - 10) >> 8) & ^38)) << 8 |
                    (87 + b + (((b - 10) >> 8) & ^38)));
        hex[i*2] = byte(x);
        x >>= 8;
        hex[i*2 + 1] = byte(x);
        i++;
    }
    hex[binLen*2] = 0;

    return hex, nil;
}


Please note a few key changes:

- Since Go does not have explicit reference types like C, Go's `[]byte` (which is slice of `byte`) was used for both `hex` and `bin`. It behaves like the arrays in C.
- Since Go does not provide preprocessor installations, the validation step `sodium_misuse()` is instead done by returning an error object which can hold the context of the error.
- Conversion functions (`byte()`) are used for type casting.

Any variances here arise because the coding practices vary between off the languages regarding resource management and error handling.