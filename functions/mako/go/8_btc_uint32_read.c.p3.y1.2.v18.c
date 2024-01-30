golang
func btc_uint32_read(zp *uint32, xp *[]byte, xn *int) bool {
    if *xn < 4 {
        return false
    }

    if isBigEndian() {
        *zp = (uint32((*xp)[0]) << 0) |
            (uint32((*xp)[1]) << 8) |
            (uint32((*xp)[2]) << 16) |
            (uint32((*xp)[3]) << 24);
    } else {
        *zp = binary.LittleEndian.Uint32(*xp)
    }

    *xp = (*xp)[4:]
    *xn -= 4

    return true
}

// function to check the endianness of the system
// no other go standard way to determine system endianness
// need write and read back performance will vary based on OS Disk Cache
func isBigEndian() bool {
	var i int32 = 0x01020304

	// pointer to int32, through pointer to byte gets the first byte
	u := *(*byte)(unsafe.Pointer(&i))

	return u == 0x01
}
