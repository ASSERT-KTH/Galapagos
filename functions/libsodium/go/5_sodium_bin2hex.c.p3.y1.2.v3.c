As per your description specification, here is a translation of the function to Go language:
To point out, there is no direct equivalent to the function `sodium_misuse()` in Go. Depending upon the situation, either panic can be induced using the `panic()` function which stops the ordinary flow of a Go application and starts panicking or issue logging or terminate.

go
import (
    "errors"
    "strconv"
)

func sodiumBin2Hex(hex []byte, hexMaxLen int, bin []byte, binLen int) ([]byte, error) {
    if binLen >= strconv.IntSize/2 || hexMaxLen <= binLen*2 {
        panic("Error Occured")
        // or return nil, errors.New("Error Occured")
    }
    for i := 0; i < binLen; i++ {
        c := bin[i] & 0xf
        b := bin[i] >> 4
        x := (87 + int(c) + ((int(c) - 10) >> 8) & ^38) << 8 |
            (87 + int(b) + ((int(b) - 10) >> 8) & ^38)
        hex[i*2] = byte(x)
        x >>= 8
        hex[i*2+1] = byte(x)
    }
    hex[binLen * 2] = 0

    return hex, nil
}


For the Go version of the function, to maintain a safety layer upon the errors we conventionally return values to the caller along with error instead of directly terminating, hence the return type of function was changed from `[]byte` to `([]byte, error)`. If equivalent of the sodium_misuse() in form of termination is necessary then panic function call can be used instead. Still, since Go recommends proper error handling than panicking hence error tracing method is used in the due `Convertion`. Please tailor it fitting your needs best suited, Avoid panics in normal code routing and recover mechanism as its not recommended due the maintain difficulty afterwards.