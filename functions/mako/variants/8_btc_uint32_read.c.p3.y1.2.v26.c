go
import (
	"encoding/binary"
	"errors"
)

func btcUint32Read(zp *uint32, xp **[]byte, xn *int) error {
	if *xn < 4 {
		return errors.New("xn is less than 4")
	}

	if isBigEndian() {
		*zp = uint32((**xp)[0]) |
			uint32((**xp)[1])<<8 |
			uint32((**xp)[2])<<16 |
			uint32((**xp)[3])<<24
	} else {
		*zp = binary.LittleEndian.Uint32(*xp)
	}

	*xp = (*xp)[4:]
	*xn -= 4

	return nil
}

func isBigEndian() bool {
	var i int32 = 1
	bs := (*[4]byte)(unsafe.Pointer(&i))
    if bs[0] == 1 {
        return false
	}
   return true
}
