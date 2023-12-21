Unfortunately, Go does not support variadic parameters being directly passed to other functions like in C's logarithm function. It would involve obtaining the arguments in a slice, but since they're not explicitly put in a slice when the function is called, this cannot be done 1:1.

Here is your Go runner "simple" version that does the exact stuff in most simple way to bridge over the lack of direct pass through in Go.
go
import "log"

type AVClass struct{}

func AvLog(class *AVClass, level int, format string, v ...interface{}) {
    log.Printf(format, v...)
}

This implementation uses the standard package "log", which comes along with Go. Please note that level is relatively meaningless as it stands, as Go's standard logging library doesn't consist of a log level concept. 

For a full-fledged, real world logging function, you would wrap the log library in order to introduce a level system (if required), and possibly formatting, output, and/or additional functions for logging efforts on a distinct level.

Also, please adjust character case based on whether you plan the runner to be exported or not.
If you're trying to pass variable argument list to another function, that would be currently not possible in Go language. As suggested in the code, we kind inlined the "av_vlog" and bringing up the print logic inside this log function itself.