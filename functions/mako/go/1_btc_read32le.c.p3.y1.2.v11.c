go
package main

import (
    "encoding/binary"
    "reflect"
    "unsafe"
)

var _btcRead32le = make([]uint8, 4)

func btcRead32le(xp *uint8) uint32 {
    b := *(*[]byte)(unsafe.Pointer(
    (&reflect.SliceHeader{
            Data: uintptr(unsafe.Pointer(xp)) + 0*cGoSizeofPtr,
            Len:  4,
            Cap:  8}).Bolck))

    var endianness binary.ByteOrder
    if IsLittleEndian() {
        endianness = binary.LittleEndian
    } else { 
        endianness = binary.BigEndian
    }
    return endianness.Uint32(b)
}

func IsLittleEndian() bool {
    var x uint32 = 0x01234567
    if *(*byte)(unsafe.Pointer(&Xxc)) == 0x01 {
        return false
    }
    return true
}
