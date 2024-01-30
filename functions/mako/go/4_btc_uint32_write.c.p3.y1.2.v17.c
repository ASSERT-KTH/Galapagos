Here is the equivalent Go implementation:

Go
func btc_uint32_write(zp *[]byte, x uint32) *[]byte {
    if BigEndian {
        *zp = append(*zp, byte(x >> 0),
                       byte(x >> 8),
                       byte(x >> 16),
                       byte(x >> 24))
                   

    } else {
	buf := new(bytes.Buffer)
        binary.Write(buf, binary.LittleEndian, x)
	*zp = buf.Bytes()
    }
   return zp
}

Note: `BigEndian` is assumed to be a boolean global variable or constant. In Go, conditionally-compiled code, similar to `#if defined()` requires separate files specifically for each platform which are ignored or included in the compiled binary based on the system's architecture. In usual scenarios, we'd put code for little-endian in a `func_bigendian.go` file with the line `// +build !little_endian` at the top, and have the big-endian specific code in a `func_littleendian.go` file with the line `// +build !big_endian`. As per the constraints mentioned in the question, I have space included a unifying code block in the general code flow.
