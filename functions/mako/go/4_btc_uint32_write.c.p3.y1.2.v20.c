go
import (
    "encoding/binary"
    "unsafe"
)

func btcUint32Write(zp unsafe.Pointer, x uint32) unsafe.Pointer {
    if isBigEndian() {
        *(*byte)(zp) = byte(x >> 0)
        zp = unsafe.Pointer(uintptr(zp) + 1)
        *(*byte)(zp) = byte(x >> 8)
        zp = unsafe.Pointer(uintptr(zp) + 1)
        *(*byte)(zp) = byte(x >> 16)
        zp = unsafe.Pointer(uintptr(zp) + 1)
        *(*byte)(zp) = byte(x >> 24)
    } else {
        binary.LittleEndian.PutUint32((*[4]byte)(zp)[:], x)
        zp = unsafe.Pointer(uintptr(zp) + 4)
    }
    return zp
}

func isBigEndian() bool {
    var x uint32 = 0x01234567
    if *(*byte)(unsafe.Pointer(&x)) == 0x01 {
        return true
    }
    return false
}
