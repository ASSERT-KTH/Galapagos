func btc_uint32_read(zp *uint32, xp *[]byte, xn *int) bool { 
    if *xn < 4 { 
        return false 
    } 

    if isBigEndian() { 
        *zp = (uint32((*xp)[0]) <<  0) | 
             (uint32((*xp)[1]) <<  8) | 
             (uint32((*xp)[2]) << 16) | 
             (uint32((*xp)[3]) << 24) 
    } else { 
        *zp = binary.LittleEndian.Uint32(*xp) 
    } 

    *xp = (*xp)[4:] 
    *xn -= 4 

    return true 
 }

func isBigEndian() bool {
    var i uint32 = 0x01020304

    byte := (*[4]byte)(unsafe.Pointer(&i))

    return byte[0] == 0x01
}