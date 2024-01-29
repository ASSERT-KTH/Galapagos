func btc_uint32_read(zp *uint32, xp *[]uint8, xn *int) int {
    if (*xn < 4) {
        return 0
    }

    if isBigEndian() {
        *zp = (uint32)((*xp)[0] <<  0) |
            (uint32)((*xp)[1] <<  8) |
            (uint32)((*xp)[2] << 16) |
            (uint32)((*xp)[3] << 24)
    } else {
        *zp = *(*uint32)(unsafe.Pointer(&(*xp)[0]))
    }

    *xp = (*xp)[4:]
    *xn -= 4

    return 1
}

func isBigEndian() bool {
    var i int32 = 0x01020304
    u := unsafe.Pointer(&i)
    pb := (*byte)(u)
    return *pb == 0x01
}