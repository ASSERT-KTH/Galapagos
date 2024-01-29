import "encoding/binary"

func btc_uint32_read(zp *uint32, xp *[]byte, xn *int) bool {
	if *xn < 4 {
		return false
	}

	*zp = binary.LittleEndian.Uint32((*xp)[:4])
	*xp = (*xp)[4:]
	*xn -= 4

	return true
}