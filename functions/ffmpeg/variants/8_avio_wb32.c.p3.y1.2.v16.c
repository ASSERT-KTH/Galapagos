Given that Go doesn't have direct bit manipulation functions analogous to 'w8' methods present in C function. Anyway, you can replicate this functionality using standard Go libraries:
 go
import (
    "encoding/binary"
    "io"
)

func avioWb32(s io.Writer, val uint32) {
    buf := make([]byte, 4)
    binary.BigEndian.PutUint32(buf, val)
    s.Write(buf)
}

This Go function `avioWb32` does the equivalent of the provided C function. 

There could be any errors during writing to Writer interface, all of this should be handled correctly, but it left beyond the function because question is about direct translation. 

Important note, be aware about endianness even if it's not specified, you never know how rest of system handle this part without documentation. In this case more safe way to specify that when translating from C is use BigEndian.