Here is the equivalent Go code:

Go
import (
    "encoding/binary"
    "unsafe"
)

func btc_uint32_write(zp *byte, x uint32) *byte {
    if isBigEndian() {
        *zp = byte(x >> 0)
        zp = unsafe.Pointer(uintptr(unsafe.Pointer(zp)) + 1)
 
        *zp = byte(x >> 8)
        zp = unsafe.Pointer(uintptr(unsafe.Pointer(zp)) + 1)
 
        *zp = byte(x >> 16)
        zp = unsafe.Pointer(uintptr(unsafe.Pointer(zp)) + 1)
 
        *zp = byte(x >> 24)
    } else {
        binary.LittleEndian.PutUint32((*[4]byte)(unsafe.Pointer(zp)), x)
        zp = unsafe.Pointer(uintptr(unsafe.Pointer(zp)) + 4)
    }
 
    return zp
}



Note: Go does not natively support pointer incrementation which C supports. When handling binary data or low-level manipulations of data, Go tends to enforce a safer development approach that focuses on types. However, Go have pointer manipulation operation delivered in the unsafe system library including hazardous direct memory manipulation. It is suitable for kernel programming or places where really need special memory layout, and generally used as few as possible in daily code due to the risk caused by unsafe keyword.

Also, unlike C, Go does not directly support testing at compile-time for endianness, meaning an isBigEndian function would need to be implemented to dynamically test at run-time.

In Go Expressions like:

                     binary.LittleEndian.PutUint32(zp, x)
                     
bare a stronger intent and are more self-explanatory when a developer is to do machine-specific bit modifications. It helps in maintainability and gives the underlying abstraction better and safer semantic meaning in Go.
