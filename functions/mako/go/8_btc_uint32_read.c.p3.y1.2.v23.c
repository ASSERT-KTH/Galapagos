In Go, a semantically equivalent version of the btc_uint32_read function can look like this:

go
import (
    "encoding/binary"
    "errors"
)

type BtcUint32Read struct {
	zp *uint32
	xp **[4]uint8
	xn *int
}

func NewBtcUint32Read() *BtcUint32Read {
	return &BtcUint32Read{}
}

func(b *BtcUint32Read) Unt32Read(zp *uint32, xp **[4]uint8, xn *int) error {
	if *xn < 4 {
		return errors.New("length must be greater than or equal to 4")
	}

	*zp = binary.LittleEndian.Uint32((*xp)[:])

    *xp = &(*xp)[4:]
	*xn -= 4

	return nil
}


In this go code:
* The function has been encapsulated in a struc `BtcUint32Read`, this allow us for managing the state properly.
* `Unt32Read` accepts pointers to a uint32 (`zp`), a pointer to an array of 4 uint8s (`xp`), and a pointer to int (`xn`) parameters. It returns an error, which can be checked by the calling code, instead of the 0 or 1 returned in the previous  C implementation to represent if the function run successful or not.
* The import packages at start of the code are standard library packages within Go for handling various data types. Importantly "encoding/binary" is used to handle byte order encoding and decoding.
* Package `errors` is to return any error like less than 4 length.
* The code uses the built-in function `binary.LittleEndian.Uint32` to convert the first 4 bytes stored in the array `xp` to a `uint32` without having need to shift manually for Big Endian/Little endian orientation, thereby simplifying the equivalent function in Go.
* Before the conversion, the function checks if the length `xn` is less than 4, and if so, returns an error, as C version `-1` return value.
* After the bit conversion, xp and xn are adjusted accordingly, similarly with the original C function.