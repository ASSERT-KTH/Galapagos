Here is a semantically equivalent version of this function in Go:

go
func putBits(s *Jpeg2000EncoderContext, val int, n int) { // TODO: optimize
    for n > 0 {
        n--
        if s.bitIndex == 8 {
            if *s.buf == 0xff {
                s.bitIndex = 1
            } else {
                s.bitIndex = 0
            }
            s.bufIndex++
            s.buf[s.bufIndex] = 0
        }            
        s.buf[s.bufIndex] |= byte(val << (7 - s.bitIndex))
        s.bitIndex++
    }
}


I made a assumption about the design of your Go structure since it was not provided. This structure would look something like this:

go
type Jpeg2000EncoderContext struct {
    bitIndex int
    bufIndex int
    buf []byte
}


Just as you asked, maintained the initial signature (two integer arguments), semantics (the way bit manipulation and bit array management works) and the TODO you left inside (which I assume were for you to remember to eventually optimize the execution time of the function by looking for different implementation strategies in the future).
In C, array identification is accomplished via a pointer to an element of the array (buf), but in Go, is better splitting this into a slice (a more flexible, higher-level array) and an index member (bufIndex), we use the latter to manage navigation through the array like a pointer would in C. Despite being more idiomatic in Go to manage this kind of iteration fully by range verb, you could totally replace bufIndex with a real pointer in Go if that is absolutely required, but wouldn’t be idiomatic.