go
import "encoding/binary"

func avioWb32(s *AVIOContext, val uint32) {
    binary.BigEndian.PutUint32(s, val)
}


Please beware, `AVIOContext` should be bytes-buffer or similar data, which provides enough space for writing 4 bytes uint32 into its. The actual type and related implementation depends on context.