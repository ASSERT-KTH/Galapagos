Here is an equivalent version of the function in Go:

go
import (
	"encoding/binary"
	"errors"
)

func btcUint32Read(zp *uint32, xp *[]byte, xn *int) error {
	if *xn < 4 {
		return errors.New("Insufficient bytes")
	}
	
	*zp = binary.LittleEndian.Uint32(*xp)

	*xp = (*xp)[4:]
	*xn -= 4

	return nil
}

Go does not return error codes like C, so I've used error built-in type to indicate the same error (not enough bytes). An error value of 'nil' indicates everything went successful. 

In Go 'size_t' translates to 'int' and rather than changing the bp's array value it updates xp's slice that simply refers relevant part of memory array as slices in go are simply reference to the array section, just increasing the index pointer will drop the read bytes. Hence following go idiomatic behaviour. 

Finally Go has a built in package 'encoding/binary' assuming machine is little-endian. The binary.LittleEndian.Uint32(*xp) replaces the need to bite-shifting and or-ing due to Go's built in little endian handling. Please revise if in case your machine is big-endian.