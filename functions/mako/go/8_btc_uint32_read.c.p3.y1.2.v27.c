The Go function with a similar function signature may have the following form:

go
func btc_uint32_read(zp *uint32, xp *[]byte, xn *int) bool {
  if *xn < 4 {
    return false
  }

  buffer := bytes.NewReader(*xp)

  if err := binary.Read(buffer, binary.LittleEndian, zp); err != nil {
    log.Fatal("binary.Read failed", err)
  }

  *xp = (*xp)[4:]
  *xn -= 4

  return true
}


Several things to note is that Go handles endianess specifically with its binary package. The necessity of checking for an error is due to this package also being responsible for reading and writing large amounts of data, running out of room, inability to seek to appropriate run and so forth.

Unfortunately "Maintain the original function's signature(In return data type)" in golang is not entirely possible, as it doesn't allow us to return ok points unlike C. We may have to alternately use 'bool' instead of 'int' as response flag. 

The usage of 'bool' also makes sense given that the function merely verifies whether reading was successful or not.