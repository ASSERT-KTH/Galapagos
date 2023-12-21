The C program represents bit manipulation occurring in a database related to JPG files. Here it returns integer values depending on the bits they are trying to query. A similar function with Go syntax would look something like this:

Go
func getBits(s *Jpeg2000DecoderContext, n int) int {
    res := 0

    for n--; n >= 0; n-- {
        res = res << 1
        if s.bitIndex == 0 {
            bytestream2GetByte(&(s.g))
            if s.g[len(s.g)-1] != 0xFF {
                s.bitIndex = 7
            } else {
                s.bitIndex = 8
            }
            
        }
        s.bitIndex--
        res = res | ((s.g[len(s.g)-1]>> uint(s.bitIndex)) & 1)
    }
    
   return res
}

Please note that Go handles bitwise operations differently than ANSI C, especially when it comes to shifts by a negative amount. For left and right shifts, the shift count has to be a nonnegative unsigned integer.
Moreover, the module or packages related to the bytestream2 (`bytestream2_get_byte`, `bytestream2_peek_byte`) aren't exactly there in golang and has been improvised in the above function.

Also, the struct `Jpeg2000DecoderContext` would be defined as follows:
Go
type Jpeg2000DecoderContext struct {
    bitIndex int
    g []uint8
}
 

Please make sure you replace structs or function calls not shown above before running the code, and modify it according to your own requirements to make it functional in your Go program. Please note that, C language and Go handle pointers differently and you need to align any specific pointer based operation or access according to Go syntax as well.