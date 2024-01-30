go
func btcRead32le(xp []byte) uint32 {
    // Assuming LittleEndian or BigEndian as appropriate.
    if binary.BigEndian {
        return uint32(xp[0]) +
            uint32(xp[1])<<8 +
            uint32(xp[2])<<16 +
            uint32(xp[3])<<24
    } else {
        return binary.LittleEndian.Uint32(xp)
    }
}

Please, note that `binary.BigEndian` is not a valid constant or variable in Go. I used it in the same manner how `BTC_BIGENDIAN` was used in the C code, but you might change this to suit your needs in actual Go code. Check your desired endianness before calling the `Uint32()` methods from the `encoding/binary` standard library package.