The Go Programming Language does not support function overloading with class-like structures, like it is common in languages such as C++. Therefore, a direct conversion from T::f(args...) to T.f(args...) will not be semantically equivalent because it can alter the value-passing semantics in Go.

But you can have similar functionality with Go's methods. To mirror your example, in C, the function takes a structure `Jpeg2000EncoderContext` as a pointer parameter `s`, modifies the parameter internally, and doesn't return anything, i.e., it's void. A similar equivalent would be a method of the `Jpeg2000EncoderContext` struct.

Here's how the equivalent Go function would look like.

go
type Jpeg2000EncoderContext struct {
    bit_index int
    buf *[]byte //is a pointer to a byte slice
}

func (s *Jpeg2000EncoderContext) putBits(val, n int) {
    for n > 0 {
        if s.bit_index == 8 {
            if (*s.buf)[0] == 0xff {
                s.bit_index = 1
            } else {
                s.bit_index = 0
            }
            
            newBuf := make([]byte, len(*s.buf)+1) //Increase buffer size
            copy(newBuf, *s.buf)
            s.buf = &newBuf
        }
        (*s.buf)[0] |= byte(val) << (7 - byte(s.bit_index))
        s.bit_index++
        n--
    }
}


This code sums up several things:

- Changed "`s->`" to "`s.`" because Go uses "dot" syntax rather than "->" to reference fields/.
- Changed "`*s->buf`" to "(*s.buf)[0]" because Go doesn't support "->" syntax. "?" more stylistically idiomatic in Go to refer deferenced pointer to slice item.
- Changed "`*(++s->buf)`" to "`s.buf = &newBuf`". In C, "*(++s->buf)" moves the pointer to next buffer address and assigns 0 value. This incantation is not valid in Go and you have to explicitly make a new bigger slice, copy old values and ref point the buf pointer.
- "`*s->buf |= val << (7 - s->bit_index++)`" equates to "(*s.buf)[0] |= byte(val << (7 - s.bit_index))". It puts bits into buffer whereby Go's "|=" operator does an OR on the existing value and provided missing bit information from caller are filled in using direct allocation since Go does not allow direct memory manipulation.
- Also you would note keyword usage "`type`" equivalent for to the "struct" in C and "`func`" in place of "static void".

This function will receive input, process the changes, and mutate `Jpeg2000EncoderContext` in place without needing to return anything, similar to the given C Code. However the resulting Go code pointer semantics would still be slightly varied compared to the actual execution of C code's version in memory.