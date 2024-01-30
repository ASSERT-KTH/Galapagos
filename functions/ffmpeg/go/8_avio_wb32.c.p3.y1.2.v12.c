go
package main

type AVIOContext struct {
    // function context details
}

func avio_w8(c *AVIOContext, val uint8) {
    // implement function details accordingly
}

func avio_wb32(s *AVIOContext, val uint32) {
    avio_w8(s, uint8(val>>24))
    avio_w8(s, uint8(val>>16))
    avio_w8(s, uint8(val>>8))
    avio_w8(s, uint8(val))
}

I have assumed that `AVIOContext` struct and `avio_w8`function are previously defined, and I translated your C code into an equivalent function written in Go lang.