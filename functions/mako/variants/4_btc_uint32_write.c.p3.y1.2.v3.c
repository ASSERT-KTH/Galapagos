go
import (
    "encoding/binary"
    "unsafe"
)

func btc_uint32_write(zp *uint8, x uint32) *uint8 {
    if binary.BigEndian != binary.LittleEndian {
        *zp = uint8(x)
        zp += uintptr(unsafe.Pointer(zp))
        *zp = uint8(x >> 8)
        zp += uintptr(unsafe.Pointer(zp))
        *zp = uint8(x >> 16)
        zp += uintptr(unsafe.Pointer(zp))
        *zp = uint8(x >> 24)
    } else {
        binary.LittleEndian.PutUint32((*[4]byte)(unsafe.Pointer(zp))[:], x)
        zp += 4
     }
     return zp
}
 

Note: Go does not promote casting or unsafe.Pointer usage and there's no direct equivalent since usage of pointers are discouraged. If the intent is to directly manipulate memory (as original C code), 'unsafe' scope is what we need but it is not a general or idiomatic Go usage. A better equivalent would be to implement via idiomatic slice handling, like below (using byte slices as function parameter instead of pointer):

go
import (
    "encoding/binary"
)

func btc_uint32_write(buffer []byte, value uint32) []byte {
    binary.LittleEndian.PutUint32(buffer, value)
    return buffer[4:]
}
