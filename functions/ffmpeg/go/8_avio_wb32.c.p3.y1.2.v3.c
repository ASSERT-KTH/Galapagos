package main

import (
	"encoding/binary"
	"io"
)

type AVIOContext struct {
	writer io.Writer
}

func avio_wb32(s *AVIOContext, val uint32) {
	binary.Write(s.writer, binary.BigEndian, val)
}