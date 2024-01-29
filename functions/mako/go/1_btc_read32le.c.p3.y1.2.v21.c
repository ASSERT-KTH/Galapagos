The following code is semantically equivalent in Go:

go
import "encoding/binary"

func btc_read32le(xp []byte) uint32 {
    if binary.BigEndian {
        return  uint32(xp[0]) |
                uint32(xp[1])<<8  |
                uint32(xp[2])<<16  |
                uint32(xp[3])<<24
    } else {
        return binary.LittleEndian.Uint32(xp)
    }
}


Note: Unlike in C, Go's `binary.BigEndian` is not a flag that can be set saying the machine is Big-Endian or Little-Endian. It is actually the Big Endian implementation to convert multi-byte values to integers.

The version in the new code assumes the workflow to be Big Endian as there is no way checking if the endianess inside application in go. It will work the exact same way as the original function regardless of the underlying system architecture, as it forces BigEndian in one case and use LittleEndian in the other.

With the Go language, It's generally more common to explicitly define the Endianess of the code, rather than relying on system's architecture. That's explicitly clarified in the concept of Binary package in Go which enables reading and writing of the binary files in a user specified format/endianess.