Here is the semantically equivalent function in the Go programming language:

go
func btc_read32le(xp []byte) uint32 {
    if binary.BigEndian.Uint16([]byte{1, 0}) == 1 {
        return uint32(xp[0]) |
            uint32(xp[1])<<8 |
            uint32(xp[2])<<16 |
            uint32(xp[3])<<24
    } else {
        return binary.LittleEndian.Uint32(xp)
    }
}
