go
import (
    "encoding/binary"
    "unsafe"
)

func btcUint32Read(zp *uint32, xp *[]byte, xn *int) int {
    if *xn < 4 {
        return 0
    }

    if binary.BigEndian {
        *zp = binary.BigEndian.Uint32(*xp)
    } else {
        *zp = binary.LittleEndian.Uint32(*xp)
    }

    *xp = (*xp)[4:]
    *xn -= 4

    return 1
}

Unfortunately, because Go is a safe language, it doesn't guarantee an array of arbitrary bytes contain valid full encodings of `uint32`s, also there's no identical way to handle BOTH endians based on a macro like the OP's code. 

However, by using the standard "encoding/binary" package, arrays of arbitrary bytes can be translated into `uint32`s in either LittleEndian or BigEndian endianess.

Since "encoding/binary" works on arrays of bytes, I followed this assumption to define `xp` in my Go code, keeping the interface semantically closer to the C implementation, based on the usage of the given parameters `zp`, `xp`, `xn` in the main core of OP's code. 

This produced similar input/output characteristics slightly resembling original C function.