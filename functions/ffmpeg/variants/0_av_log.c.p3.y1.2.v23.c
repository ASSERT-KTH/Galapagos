Go doesn't support variadic arguments the same way as C. 

And also Go does not support the fprintf function, which takes a pointer as an argument. 

However, employing the log package you could build semantics analogous to original function in the following way:

go
import "log"

func av_log(avcl interface{}, level int, fmt string, v ...interface{}) {
    log.Printf(fmt, v...)
}


This snippet makes use of Go's interface{} type for replacing void*, as well as '...' in function parameters to replace variadic behaviour from original function. A Printf method with this property joins these values into a string based on 'fmt'. Note that the above example patterns a simplified logging functionality in Go. 

Features of original function like va_start, va_end, and av_vlog() aren't analogously translated into Go. These semantics lean more closely to variable arguments features in C which have a different conduct in Go appearing to be more intricate to mirror to an equivalent version directly. Purpose-original translation would imply rewriting your logging in Go.