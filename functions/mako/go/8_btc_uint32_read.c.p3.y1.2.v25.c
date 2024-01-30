func btcUint32Read(zp *uint32, xp *[]byte, xn *int) int {
    if *xn < 4 {
        return 0
    }

    if isBigEndian() {
        *zp = (uint32((*xp)[0]) << 0) |
            (uint32((*xp)[1]) << 8) |
            (uint32((*xp)[2]) << 16) |
            (uint32((*xp)[3]) << 24)
    } else {
        *zp = binary.LittleEndian.Uint32(*xp)
    }

    *xp = (*xp)[4:]
    *xn -= 4

    return 1
}

var (
    systemEndian binary.ByteOrder = binary.BigEndian
)

func init() {
    {
        var swapTest int32 = 0x1
        x := (*[4]byte)(unsafe.Pointer(&swapTest))[:]
        if x[0] > 0 {
            systemEndian = binary.LittleEndian
        }
    }    
}

func isBigEndian() bool {
    return systemEndian == binary.BigEndian
}