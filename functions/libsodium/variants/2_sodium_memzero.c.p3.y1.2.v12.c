In the Go programming language, the `bytes` package has a built-in function for setting all the bytes of a slice to a particular value. Like its C counterpart, you would use the `bytes` package `Repeat` function, and repeat a `0` value to represent a "clean" byte, In a tedious case we would do that in Lopp. Here is your solution:

Go
import (
    "bytes"
)

func sodium_memzero(pnt []byte, len int) {
    zeros := bytes.Repeat([]byte{0}, len)
    copy(pnt, zeros)
}


Please make sure `pnt` slice has adequate room, otherwise memory will not be overwritten up to `len`.