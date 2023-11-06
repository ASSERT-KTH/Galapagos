Here is the semantically equivalent Go implementation of the above function:

go

import "errors"
import "strconv"

func sodiumBin2Hex(bin []byte, hex *[]byte)  error {
    if len(bin) >= 1 << 30 || cap(*hex) <= len(bin) * 2 {
        return errors.New("invalid Argument")
    }

    *hex = (*hex)[:0]

    for _, c := range bin {
        x := strconv.FormatInt((int64(c & 15)| (int64(c) >> 4 << 8)), 16)      
        *hex = append(*hex, x...)
    }

    return nil
}

This function, sodiumBin2Hex, takes an unsigned binary buffer as the input, bin, as well as a pointer to an output buffer, hex.

Then it checks whether parameters comply with constraints before iterating over the elements in the binary input.

For every character in the buffered Binary Input , it generates a Hexadecimal values and strings these hex values as they are available.

Is then appended to the Hex buffer keeping the constriants in mind for memory limits using append() of Golang.

Also in case condition not met, provision are made to raise specific error for invalid argument by error package.