Assuming that the coin library in Go inherits from the package binary and that the order effects little-endian/big-endian to correctly render the representation according to architecture,  here is how the function would look in Go:

go
import (
    "encoding/binary"
)

func btc_uint32_write(zp []byte, x uint32) []byte {
   binary.LittleEndian.PutUint32(zp, x)
   return zp
}


Please, note that in the 'C' version, if the system is not BIGENDIAN it performs a memcpy assuming little-endian layout, therefore I replicated it to little-endian in Go too.

Also worth noticing that this function will assume that 'zp' has at least '4' places to store the uint data type, which will need to be verifies in the call.