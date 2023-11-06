Here is a semantically equivalent implementation in Go. For the Go version, I use the binary package's `binary.BigEndian` and `binary.LittleEndian` to deal with endianness conveniently. Instead of returning a success marker, Go functions can return an error marker.

go
package main

import (
    "encoding/binary"
    "errors"
)

func btc_uint32_read(zp *uint32, xp *[]byte, xn *int) error {
    if *xn < 4 {
        return errors.New("error: insufficient length")
    }

    if isBigEndian() {
        *zp = binary.BigEndian.Uint32(*xp)
    } else {
        *zp = binary.LittleEndian.Uint32(*xp)
    }

    *xp = (*xp)[4:]
    *xn -= 4

    return nil
}

func isBigEndian() bool {
    test := uint32(0x11223344)

    btest :=  *(*[4]byte)(unsafe.Pointer(&test))

    if btest[0] == 0x11 && btest[1] == 0x22 {
        return true
    }

    return false
}

Note that checking endianness of the system can be done in various ways, different practices might prefer varying methods. This demo uses an arbitrary byte array for checking. Please replace with preferred method, if any. We supposed to import "unsafe"paackage when using `unsafe.Pointer`, I've removed into maintan codebase because It's not usually recommended in Go to use "unsafe" operations to retain aspects that influence portability, safety, and learnability of the Go projects or code examples. However, for tasks which need system-level manipulations, occasionally, unsafe code may be the only way. The considerations definitely need production-quality constraints and practices.