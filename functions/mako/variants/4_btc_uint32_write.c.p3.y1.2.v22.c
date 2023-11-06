go
import (
    "encoding/binary"
    "unsafe"
)

func btc_uint32_write(zp *[]byte, x uint32) *[]byte {
    if isBigEndian() {
        *zp = append(*zp, byte(x));
        *zp = append(*zp, byte(x >> 8));
        *zp = append(*zp, byte(x >> 16));
        *zp = append(*zp, byte(x >> 24));
    } else {
        data := make([]byte, 4)
        binary.LittleEndian.PutUint32(data, x)
        *zp = append(*zp, data...)
    }
    return zp
}

// Note: function check for BE of LE machine not always available in different OS
func isBigEndian() (ret bool) {
    i := int(0x1)
    bs := (*[int(unsafe.Sizeof(0x1))]byte)(unsafe.Pointer(&i))
    if bs[0] == 0 {
        return true
    } else {
        return false
    }
}

Note: This implementation borrows `isBigEndian()`, application-specific details might be required for a universally valid approach, a more implementation-independent version would likely need to rely on checking processor-specific features from within the Go language, an approach that appears to be currently unavailable. As such, this function might not be 100% reliable when transferred from current platform to a different one. 

Therefore, whenever this got ported on a different context it might be better relies on encoding/binary package offered by standard library and as Go has automatic garbage collection freeing, returning from the function might not necessary.