There is no equivalent context in Go as AVIOContext in C. Since the description original code lacks context on explaining what AVIOContext relationship is with the functionality, it is a bit difficult to write a similar functionality program in Go.

However, understanding from the code, it is writing an uint in BigEndian byte order and the 'avio_w8' does the writing. You can reproduce the exact same functionality with encoding/binary provided by Go. But the signature will change as there is no similar context of AVIOContext in Go.

Here is little modification for similar kind of operation : 

go

import (
    
    "encoding/binary"
    "io"
)

func avio_wb32(w io.Writer, val uint32) {
   buf := make([]byte, 4)
   binary.BigEndian.PutUint32(buf, val)
   w.Write(buf)
}

In this function, io.writer should be position in the stream where you need to write byte and pass appropriate value to val variable where stream starting position is sought. This will mimic expected functionality.  Because there is no equivalent Go alternative for AVIOContext your function would look like this.