go
import "encoding/binary"

func btc_uint32_read(zp *uint32, xp *[]byte, xn *int) int {
	if *xn < 4 {
		return 0
	}

	// assuming little endian
	*zp = binary.LittleEndian.Uint32(*xp)

	*xp = (*xp)[4:]
	*xn -= 4

	return 1
}

Please note that this function assumes the byte order is "little endian" as most systems today use. If you want the "big endian", replace `LittleEndian` with `BigEndian`. The original C function uses `memcpy` for little endian platforms, which effectively reads in "little endian" way, and manually undergoes a "big endian" read when explicitly defined.