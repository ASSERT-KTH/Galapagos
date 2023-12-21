Sorry, but it is incorrect to keep the same function signature during converting this specific function to Go. That's because Go doesn't have built in classes or the shorthand method for defining pointer-to-class methods used in this specific C function. Anyway, letting aside this consideration, I will rephrase this function using "golang".

Go
func (s *Jpeg2000DecoderContext) getBits(n int) int {
    res := 0

    for ; n > 0; n-- {
        res <<= 1
        if s.BitIndex == 0 {
            if s.G.getByte() != 0xFF {
                s.BitIndex = 8
            } else {
                s.BitIndex = 7
            }
        }
        s.BitIndex--
        res |= (s.G.peekByte() >> s.BitIndex) & 1
    }
    return res
}

Struct in Go instead of a class will look like:

Go
type Jpeg2000DecoderContext struct {
    BitIndex int
    G        BitStream2 
}

type BitStream2 struct{
    // something needs to be here which provide methods/functions getByte() and peekByte()
}


Again, this replacement is in attempt to convert equivalent function means may need BitStream2 object to be defined based on requirements which provide `getByte()` and  `peekByte()` methods to satisfy this transformation in languages. There could be compilation error if proper definition of BitStream2 is not provided or used. Those must be methods not pure functions because they will likely need to use and possibly modify current state of g which would be impossible by functions as they cannot change their input in go.