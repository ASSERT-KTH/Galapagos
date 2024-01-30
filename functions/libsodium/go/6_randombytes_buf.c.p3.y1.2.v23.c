import (
    "crypto/rand"
    "io"
)

func RandomBytesBuf(buf []byte, size int) {
    if size > 0 {
        _, err := io.ReadFull(rand.Reader, buf)
        if err != nil {
            panic(err)
        }
    }
}