Unfortunately, the Go programming language does not support classes or methods with instance-specific state like you would in C++. Instead, the design of Go centers around Types (equivalent to a class), methods on types and functions.

Further, Go uses package level privacy instead of class level privacy. That means if something starts with a capital letter then it is Public otherwise it is Private. In C whether global or Module level, not possible to access outside the function - only copy of it you access while you call. Due to this, it's not possible to maintain the exact original function's signature. 

However, we can create equivalent feature by using a struct to hold the context (like s in the C function), and making `getBits` a method linked to that struct. Here's how you could approach it with the package bitstream wrapper.

Go
package main
import (
    "io"
    "github.com/dgryski/go-bitstream"
)

type Jpeg2000DecoderContext struct {
    bitIndex int
    g io.Reader
}

func (s *Jpeg2000DecoderContext) getBits(n int) int {
    res := 0
    bw := bitstream.NewReader(s.g)

    for n--; n >= 0; n-- {
        res <<= 1
        if s.bitIndex == 0 {
            byte, _ := bw.ReadBits(8)
            s.bitIndex = 7 + (byte != 0xFF)
        }
        s.bitIndex--
        bit, _ := bw.ReadBit()
        res |= int(bit) >> uint(s.bitIndex) & 1
    } 
    return res
}

Please be aware of handling errors such as End of Reader on every bit read. You might want to handle those appropriately based on the requirement of your application, one possible constant return in those scenarios can be -1 or a predetermined magic number otherwise handle through error return (change in signature is required for error return).