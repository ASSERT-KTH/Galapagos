Since Go does not support method overloading like C, the solution will simply consist of 4 separate write operations within the function instead.

Assuming 'avio_w8' as 'WriteByte', which is a method that writes a single byte:
go
func AvioWb32(s *AVIOContext, val uint32) {
    s.WriteByte(byte(val >> 24))
    s.WriteByte(byte(val >> 16))
    s.WriteByte(byte(val >> 8))
    s.WriteByte(byte(val))
}

This is under assumption that 'AVIOContext s' was implemented with method 'WriteByte' to write single byte. Refined assumption is needed for perfect translation.