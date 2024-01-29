Here is a direct conversion of your function to Go:

go
import (
     "encoding/binary"
)

type ErrorWrongSize struct {}

func (e *ErrorWrongSize) Error() string {
    return "Insufficient size"
}

func btcUint32Read(zp *uint32, xp *[]byte, xn *int) error {
    if *xn < 4 {
        return &ErrorWrongSize{}
    }
    *zp = binary.LittleEndian.Uint32(*xp)
    *xp = (*xp)[4:]
    *xn -= 4
    
    return nil
}


Please note the following:
- Go does not support erroring out just from a function. Go uses the concept of panic and recover which is unlike traditional approach of catching errors. However, in most general everyday programming, this allowed us to handle any error with responsibilities. (By the way, Go also supports panicking like throwing an exception as other language, but it's not recommended because it reduces the readability)
- An error interface is used here that behaves like inbuilt error, you can use it directly but it would be good for the larger systems where you really specific types of errors as per business statuses.
- I have assumed that BTC_BIGENDIAN is not used, and adopt little endian by default. You might need get platform info like endian and incase of BIGENDIAN need to use binary.BigEndian data type for conversion
- You need to import "encoding/binary" package to to convert little endian byte already to uint32
- Also, have not included handling of negative sizes as existing C function does not handle minus sizes using size_t type.