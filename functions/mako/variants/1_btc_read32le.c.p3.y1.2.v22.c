Here is the equivalent function in Go, while Go doesn't have the concept of a preprocessor and hence not `#if`, `#def` directives like C. We just create two separate functions specifying endianess in the function name:

Go
import (
    "encoding/binary"
)

func btc_read32le_big_endian(xp []byte) uint32 {
    return (uint32(xp[0]) <<  0) | 
           (uint32(xp[1]) <<  8) |
           (uint32(xp[2]) << 16) |
           (uint32(xp[3]) << 24)   
}

func btc_read32le_little_endian(xp []byte) uint32 {
    return binary.LittleEndian.Uint32(xp);
}


Here we create two functions one for big-endian and one for little-endian. Although Go does support an 'unsafe' package, which would allow for a similar version of memcpy style siutation, we are advised not to use the package unless absolutely necessary.
