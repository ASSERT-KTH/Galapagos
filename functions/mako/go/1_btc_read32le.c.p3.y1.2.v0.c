The following Go code implements a semantically equivalent version of the `btc_read32le` function without considering endianess. 

go
package main

import (
	"encoding/binary"
	"fmt"
)

func btc_read32le(xp []byte) uint32 {
	return binary.LittleEndian.Uint32(xp)
}

func main() {
	byt := []byte{1, 2, 3, 4} // For testing purpose. Please remove the main function for actual use.
	fmt.Println(btc_read32le(byt))
}

This Go code is using package "encoding/binary" to convert little endian binary data to corresponding uint32.
Note, However, Go runs the binary.LittleEndian.Uint32 method on both Little and Big Endian machine.

If we really want to only go for big endian specifically, it's hard to achieve because Golang standardized avoids this kind of think to keep the code more general and portable.

A simple example of being portable is Golang's built-in function called binary.BigEndian and binary.LittleEndian to handle this kind of problem and ignore test the pcap regarding to endianness.
Therefore, to convert a C function for reading 32 little endian and big endian differently , all we can understand from this case Golang has no equivalent way to write this. 

Remember to remove the main function on actual use so the function btc_read32le can be reusable.
The main function is written for a sanity-proof, it can be modified to take user’s input or testing purposes.