go
import (
    "encoding/binary"
)

func btc_read32le(xp []byte) uint32 {
    if binary.BigEndian {
        return binary.BigEndian.Uint32(xp)
    } else {
        var z uint32
        _ = binary.Read(bytes.NewReader(xp), binary.LittleEndian, &z)
        return z
    }
}


Note:
Go has a rather different design philosophy than C. The Go standard library includes a package "encoding/binary" with functions that read data types in big-endian and little-endian, removing the need for explicit byte-shifting and ORing. Go doesn’t support pre-processing directives like in C. It isn't common (or generally approved) in Go—to conditionally compile code based on the target platform. The solution of taking endianess into account while still following common Go paradigms is applied here.
Also there is no built-in mechanism for determining the endianness of the machine in GO. Hence, binary.BigEndian is supposed to represent the required condition. But it wont change with your system's endianess. Hence, you may replace it with whichever endian your system is following.