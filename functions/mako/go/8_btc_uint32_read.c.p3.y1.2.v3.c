Here's how you could translate the `btc_uint32_read` function into Go:
Go
func btc_uint32_read(zp *uint32, xp **[4]byte, xn *int) bool {
  if *xn < 4 {
    return false
  }

  *zp = binary.LittleEndian.Uint32((*xp)[:])

  *xp = (*xp)[4:]
  *xn -= 4

  return true
}

Note: This code makes the assumption that arrays of size 4 are being passed to xp, if it may vary, consider passing and using slices instead.

Here's an equivalent function using slices instead:
Go
func btc_uint32_read(zp *uint32, xp *[]byte, xn *int) bool {
  if *xn < 4 {
    return false
  }

  *zp = binary.LittleEndian.Uint32((*xp)[:4])

  *xp = (*xp)[4:]
  *xn -= 4

  return true
}

These functions will only work with little endian byte orders, as Go's `binary.LittleEndian` was used. If you need to work with big endian byte orders, you would need to use `binary.BigEndian` instead. However, as you observed, unlike C, Go does not come with built-in detection of the endianess of an machine.
The translated function assumes the use of little endian byte order. Adjust per your needs.