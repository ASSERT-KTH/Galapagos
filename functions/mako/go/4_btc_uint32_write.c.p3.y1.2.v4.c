go
func btcUint32Write(zp []byte, x uint32) []byte {
    if isBigEndian() {
        zp = append(zp, byte(x>>24))
        zp = append(zp, byte(x>>16))
        zp = append(zp, byte(x>>8))
        zp = append(zp, byte(x))
    } else {
        binary.LittleEndian.PutUint32(zp, x)
    }
    return zp
}
// This code requires the encoding/binary package for the LittleEndian functions.
// The isBigEndian() function checks the endianness.
// In many systems, it is as follows:
// - Take a 1 byte integer and take its address as char into a pointer
// - dereference that pointer i.e., (uint16_t*) pointer to check if the MSBs of two byte integer are filled
// Bear in mind this could lead to undefined behavior

