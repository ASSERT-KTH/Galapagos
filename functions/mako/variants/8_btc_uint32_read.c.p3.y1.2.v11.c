 
import "encoding/binary"

func btc_uint32_read(zp *uint32, xp *[]uint8, xn *int) bool {
	if *xn < 4 {
		return false
	}

	if isBigEndian() {
		*zp = uint32((*xp)[0]) | uint32((*xp)[1])<<8 | uint32((*xp)[2])<<16 | uint32((*xp)[3])<<24
	} else {
		*zp = binary.LittleEndian.Uint32(*xp)
	}

	*xp = (*xp)[4:]
	*xn -= 4

	return true
}

func isBigEndian() bool {
	dummyData := [2]byte{}
	binary.BigEndian.PutUint16(dummyData[:], 0x1010)
	return dummyData[0] == 0x10
}
 
Basic difference between this code and the one of C is, that in Go we are using bool return types and we are not supporting all platform in the written code, rather it will only check is darwin processors.
If you need to run it according to system-based which are going to use this code then I would suggest using libraries i.e. `"unsafe"` in which similar function is already defined, which may not compromise the safety of your routine due to undefined behaviour and system faults due to alignment. 
So for tuning this version is a neat approximation but one would need to do further tests to decide. 
If there's another constraint not specified I will be happy to make amends. Enjoy the programming!