Here is your equivalent function in Go:

go
func btc_write32be(zp []byte, x uint32) {
    if isBigEndian() {
        binary.BigEndian.PutUint32(zp, x)
    } else {
        zp[0] = byte(x >> 24)
        zp[1] = byte(x >> 16)
        zp[2] = byte(x >> 8)
        zp[3] = byte(x)
    }
}

func isBigEndian() bool {
    var i int = 0x1
    bs := (*[4]byte)(unsafe.Pointer(&i))
    return bs[0] == 0
}


Please import:

go
import "unsafe"
import "encoding/binary"


Please notice that determine the system endianness dynamically in a language like Go create a performance penalty and maybe is really a nuance. So the best practice would be remove endianness check and use standard library to convert uint32 to bytes:

go
func btc_write32be(zp []byte, x uint32) {
  binary.BigEndian.PutUint32(zp, x)
}


Do remember to import "encoding/binary" package if you decide to follow the suggested approach.