Below is the 'sodium_bin2hex' function from C translated into a semantically equivalent version in Go:

go
func sodium_bin2hex(hex []byte, hex_maxlen int, bin []byte, bin_len int) []byte {
    if bin_len >= int(^uint(0)>>1)/2 || hex_maxlen <= bin_len*2 {
        panic("sodium misuse")
    }
    
    for i := 0; i < bin_len; i++ {
        c := bin[i] & 0xf
        b := bin[i] >> 4
        x := uint32((87 + int(c) + int((c - 10) >> 8 & ^38)) << 8|
                (87 + int(b) + int((b - 10) >> 8 & ^38)));
        hex[i*2] = byte(x)
        x >>= 8
        hex[i*2 + 1] = byte(x)
    }
    hex[bin_len * 2] = 0

    return hex
}


Notes:

1. Go does not have `const` keyword as does C++. In Go, parameters of a function are always passed by value, which means that they are effectively constants inside the called function.
2. In C, the `SIZE_MAX` is the maximum size value we can have. It is defined as the largest number of type `size_t`. In Go, to find the equivalent, we use `^uint(0)` which gives the largest `uint` number. As Go doesn't have `>>` for unsigned, applybit-wise complement operator `^` to the stored number. Thensure it deplicates an unsigned integer with binary-right operator, as `^uint(0)>>1` would give the largest value for int in Go.
3. Go doesn't support hexadecimal notation for integers. In place of '0U' and '38U', '0' & '38' is used.
5. Panic in Go is similar to an exception in other languages. Where sodiumMisuse a function call in the C code, it looks like it reports an error condition similar to panic kind function in Go. So here, replacing `sodium_misuse()` from the original C code with `panic("sodium misuse")`