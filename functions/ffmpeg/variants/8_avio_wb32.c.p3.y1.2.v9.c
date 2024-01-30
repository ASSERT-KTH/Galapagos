Unfortunately, we cannot keep the original function's signature as there's no type `AVIOContext` in Golang, however, we can use a `io.Writer` instead.

Below is the implementation in Golang :

go

import (
    "io"
    "encoding/binary"
)

func avioWb32(s io.Writer, val uint32) {
    binary.Write(s, binary.BigEndian, uint32(val))
}




Remember to keep in mind that Go doesn't support function overloading nor it can pass integers of a different sizes to a single uint32 argument. Depending on your requirement, you may have to introduce masks or explicit casts in the way you use these function. Also note that error handling is up to the caller with `binary.Write(s io.Writer, order ByteOrder, data interface{}) error`. I am omitting it here to stay with simple code as it was stated to not return anything apart from just the code. 

Therefore, this function equivalent may requires more protective code around its call, to adhere to the rules of strong typing and avoid introducing bugs on that basis.
