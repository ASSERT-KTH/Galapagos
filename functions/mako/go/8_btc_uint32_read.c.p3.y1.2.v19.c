Assuming that similar `BIG_ENDIAN` functionality didn't exist in Go native `binary` package, a Go version of the function could look like:

go
func btcUint32Read(zp *uint32, xp *[]byte, xn *int) int {
    if *xn < 4 {
        return 0
    }

    if isBigEndian() {
        *zp = uint32((*xp)[0]) | 
            uint32((*xp)[1])<<8 | 
            uint32((*xp)[2])<<16 | 
            uint32((*xp)[3])<<24
    } else {
        *zp = binary.LittleEndian.Uint32(*xp)
    }

    *xp = (*xp)[4:]
    *xn -= 4

    return 1
}

var bigEndian bool = false

func isBigEndian() (res bool) {
    uc := [2]byte{0, 1}
    if *(*byte)(unsafe.Pointer(&uc)) == 0 {
        bigEndian = true
    }
    return bigEndian
}

In the Go implementation, we're using native `binary` package to read values in little-endian form. The `isBigEndian` function is supposed to implement `ENDIANNESS` checks the endianness of the system (eg., are we on a Big Endian system or Little Endian). We want to keep it as lightweight and directly equivalent as possible. Also, since we've been instructed to avoid helper functions, we include that within the function and using a global variable `bigEndian`. As it might not be perfectly idiomatic Go code, I've protected it under a function, for performance consideration.
Remember to import relevant Go packages to your code:
go
import "encoding/binary"
import "unsafe"
                     
