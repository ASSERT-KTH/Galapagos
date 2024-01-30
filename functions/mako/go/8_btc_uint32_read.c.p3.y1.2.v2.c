go
func btcUint32Read(zp *uint32, xp *[]uint8, xn *int) bool {
    if *xn < 4 {
        return false
    }

    *zp = uint32((*xp)[0]) |
        uint32((*xp)[1])<<8 |
        uint32((*xp)[2])<<16 |
        uint32((*xp)[3])<<24

    *xp = (*xp)[4:]
    *xn = *xn - 4

    return true
}
