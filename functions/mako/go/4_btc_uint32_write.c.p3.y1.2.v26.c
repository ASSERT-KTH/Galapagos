In Go, it's important to take into account that we do not have preprocessor conditions like `#if defined`. Instead, Go manages this through binary dependent files.

One of the ways managing architecture dependent functionality in Go is by conventions on file names. For example, have two files like: `big_endian.go` and `little_endian.go` and append build tags on the first line of the files:

You also need to modify line "to use the encoding/binary library" in order to pack the uint32 variable x into the slice of bytes and this takes two arguments: the byte ordering and the actual value

Big endian (`big_endian.go`) version

go
// +build big

package main
  
import (
     "encoding/binary"
)

func btc_uint32_write(zp []byte, x uint32) []byte {
     binary.BigEndian.PutUint32(zp, x)
     return zp[4:]
}


Little endian version (`little_endian.go`)


go 
// +build !big

package main
  
import (
     "encoding/binary" 
)

func btc_uint32_write(zp []byte, x uint32) []byte {
     binary.LittleEndian.PutUint32(zp, x)
     return zp[4:]
}


In C, pointers to an array can be incremented, so return type of C function in int, however this is not allowed operation in Go, thus it will yield syntax error. They can be indexed or entirely assigned to a new location. They cannot be treated as independent variables.
For valid code, usage of return fixed-size slice pattern is instantiated. Since integer variable decremented on 4 (size of uint32), as a result pointer is incremented on series on 8 byte or 1 int per step from big endian perspective, access to index [4:] is made, returning created slice onwards from the 4th index.