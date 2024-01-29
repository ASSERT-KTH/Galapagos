The literal conversion of this code into Go would not accurately represent an equivalent 'bin2hex' function. Since Go represents bytes explicitly(buffer array in C corresponds to []byte in Go) and supports direct cast of byte to integer, it makes programs clearer and simpler. Equivalent behavior using Go's type system requires lesser checks and indirection.

Here's the Go variant:

go
package main

import "fmt"

func sodium_bin2hex(hex []byte, hex_maxlen int, bin []byte, bin_len int) []byte {
    if bin_len >= ((^0)>>1)/2 || hex_maxlen <= bin_len*2 {
          fmt.Print("Misuse")
          return hex
    }
    
  
    for i := 0; i < bin_len; i++ {
         hex[i*2] = "0123456789abcdef"[bin[i]>>4]
         hex[i*2+1] = "0123456789abcdef"[bin[i]&0x0f]
    }

    return hex 
}


In this function, hex and bin are slices of a byte, hex_maxlen and bin_len are lengths of the corresponding slices.

Please note that you need a way to handle errors like `sodium_misuse()` in the case that size of bin array would overflow the datatype limits. Go does that using Result types, which are good for returning and propagating errors. Unlike 'panic', they are not exceptions when executed, can be figured out with if else, and avail meaningful context. That part calls for:fmt.Print("Misuse").