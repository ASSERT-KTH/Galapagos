package main

import (
	"encoding/binary"
	"io"
)

type AVIOContext struct {
	w io.Writer
}

func avio_wb32(s *AVIOContext, val uint32) {
	binary.Write(s.w, binary.BigEndian, val)
}