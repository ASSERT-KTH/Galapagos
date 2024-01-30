It seems there is a misunderstanding. The function 'avio_wb32' uses an 'AVIOContext' which is a structure from 'libavformat', a part of FFmpeg written in C. 

Go does not directly run C code; so converting an FFmpeg-dependent function (like 'avio_wb32') into Go isn't possible without adapting an FFmpeg wrapper or running C from Go using CGo, which seems to be out of the asked context. However, if we consider 's' as a Write object then as a pseudocode, this could be written as:

Go 
import "io"

func avioWb32(s io.Writer, val uint32) {
    s.Write([]byte{
        byte(val >> 24),
        byte(val >> 16),
        byte(val >> 8),
        byte(val),
    })
}

It is, however, important to note that error checking ignored for brevity as 'Write' method could return a non-nil error value. Handle such cases accordingly in production-level code.