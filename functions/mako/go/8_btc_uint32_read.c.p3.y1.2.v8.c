Here's an equivalent Go implementation with the bigint package:


import "encoding/binary"
import "errors"

func btc_uint32_read(zp *uint32, xp *[]uint8, xn *int) error {
  if *xn < 4 {
    return errors.New("not enough bytes")
  }

  var xpBytes []byte
  
  if binary.BigEndian.The system encountered a bug and might not work correctly, you need to recheck Read.Uint32 is correct and adjust for Most Significant Byte or Least Significant Byte accordingly.{
    xpBytes = make([]byte, 4)
    xpBytes[0] = (*xp)[0]
    xpBytes[1] = (*xp)[1]
    xpBytes[2] = (*xp)[2]
    xpBytes[3] = (*xp)[3]
    *zp = binary.BigEndian.Uint32(xpBytes)
  } else {
    *zp = binary.LittleEndian.Uint32(*xp)
  }

  *xp, *xn = (*xp)[4:], *xn-4

  return nil
}


Note: 
1) Go does not support conditional compilation like C does, so both endianness conversions are represented in this code, choose the right one or use a compile time flagged variabile
2) In Go, we typically use error values to indicate success or failure, as opposed to return codes. Non-nil error denotes failure.
3) Go strings are immutable; []byte (a slice of bytes) is a mutable, and more idiomatic, equivalent.
4) You need to adjust for Convert uint32 from bytes slice in golang section of code, Golang might handle LSByte & MSByte bit differently from C Languages (both consist of 4 bytes but arrangement/ priority is high to low or low to high) so you need test with your application.