It should be addressed first that C "variadic" functions and Go's "variadic" functions operate in fundamentally different manners. Go's ellipsis (...) syntax doesn't directly map onto C's vaargs approach.

Additionally, implementation will differ greatly as Go doesn't use void pointers as C does, because specific type is expected in Go either by using a specific type or by utilizing interface{}, the empty interface to capture a range of types.

Thus a direct equivalent using only the functions described is nearly impossible in Go, but the following template function:
go
import "log"

func av_log(avcl interface{}, level int, fmt string, v ...interface{}) {
    log.Printf(fmt, v...)
}

works similarly to the shown C function. It accepts a formatting string and an arbitrary number of values.

Note: The avcl argument doesn't directly map to the original C function because Go doesn't use void pointers. Go has stricter typing than C.