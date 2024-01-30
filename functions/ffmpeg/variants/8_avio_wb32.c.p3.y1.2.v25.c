Unfortunately, the function signature of your C code cannot be directly translated to Go. Go doesn't support pointer parameters like your AVIOContext *s. In Go, we need either a structure with method or an interface. 

Assuming AVIOContext is a Writer which can write bytes into somewhere (just kinda behavior, might be a file, a buffer in memory, a network connection or something else), we could express your C function in Go this way:

go
import (
    "io"
    "encoding/binary"
)

func avioWb32(s io.Writer, val uint32) {
    binary.BigEndian.PutUint32(s, val)
}

Make sure to error check as required, the `binary.PutBigEndian` does not return any error (panics if there is not enough room in the output slice), most write operations in Go have a form that returns an error but this does not for use in long forms where it's opt to caller to panic or not. It might not be required here, depends on your earlier error management suits towards the upper levels. 

Finally, always make sure that your writing interface (AVIOContext) satisfies io.Writer interface. In Go, a type satisfies an interface by implementing its methods. 

To satisfy `io.Writer`, your AVIOContext struct needs to have a Write(p []byte) (n int, err error) method that matches Interface method set.

For more details, check 'Writing Files' in the File IO part of the Go documentation.