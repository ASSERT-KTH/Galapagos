Sorry, it's impossible to maintain the original function's signature because Go language doesn't support function and method overloading like the C language. In Go, we should use a different function name for different parameter types. However, below is an equivalent version of the function in Go. 

go
func avioWB32(s *avioContext, val uint32) {
    avioW8(s, uint8(val>>24))
    avioW8(s, uint8(val>>16))
    avioW8(s, uint8(val>>8))
    avioW8(s, uint8(val))
}

In the C language, we see that `avio_w8` is used, which presumably operates via a pointer `AVIOContext`. It might accept that reference and a `byte`. However specific details can't be assume absent the original program these are sourced from, so I have kept it  unaltered in this translation. This Go translates the logic of shifting and casting present in that C function. This Go functions assumes `avioW8` with comparable characteristics gets defined in the rest of your Go code.