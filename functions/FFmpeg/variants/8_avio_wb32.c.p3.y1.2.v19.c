Assuming `AVIOContext` and `avio_w8` are already implemented in Go, Here's how you can convert this function:

go
func avio_wb32(s *AVIOContext, val uint32) {
    avio_w8(s, byte(val>>24))
    avio_w8(s, byte(val>>16))
    avio_w8(s, byte(val>>8))
    avio_w8(s, byte(val))
}


This function assumes `avio_w8` expects a `byte` as second parameter and a pointer to `AVIOContext` as the first. It takes a `uint32` as an argument, breaks it down into four bytes by shifting and writes them using `avio_w8`. 

Please note that due to the lack of 'raw' context in Go unlike C where you can just push bytes into the memory, you may need to implement handlers correctly in `avio_w8` and `AVIOContext`.