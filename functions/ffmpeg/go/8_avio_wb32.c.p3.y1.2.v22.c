The C language function cannot directly be converted to Go because Go doesn't support bit-wise shift operators on types which have less than 32-bit size. We won't be able to use 'byte(val >> 16)', this won't work in Go if val is byte (or uint8), which data sizeof is 8bits. Hence, the given C function should consider `val` as a uint32. Let's consider `val` as uint32 or it's equivalent in C - unsigned int.

In Go language, it would look as follows:

go
func avio_wb32(s *AVIOContext, val uint32) {
    avio_w8(s, byte(val >> 24))
    avio_w8(s, byte(val >> 16))
    avio_w8(s, byte(val >> 8))
    avio_w8(s, byte(val))
}

The Go functions use the same logic thanks to Go's support of bitwise shift and byte conversion similar to C.
Note: AVIOContext representation (structure or interface) would need to be written in Go before the code will function correctly. The functions ‘avio_w8’ should be declared taking appropriate datatypes considering reverence and non reverent data type as per the structure to be created for “AVIOContext”. So please adjust it as per your requirement/in implementation.