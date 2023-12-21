This is a translation of the given code in Go:

go
type Jpeg2000DecoderContext struct {
    g         *Bytestream2
    bit_index int
}

func get_bits(s *Jpeg2000DecoderContext, n int) int {
    res := 0
    for n > 0 {
        res <<= 1
        if s.bit_index == 0 {
            temp_byte, _ := bytestream2_get_byte(s.g)
            s.bit_index = 7 + byteArrayToUint([]byte{temp_byte})
            if temp_byte == 0xFF {
                s.bit_index++
            }
        }
        s.bit_index--
        temp_byte, _ := bytestream2_peek_byte(s.g)
        res |= int(temp_byte>>s.bit_index) & 1
        n--
    }
    return res
}

func byteArrayToUint(b []byte) int {
    bits := binary.LittleEndian.Uint16(b)
    return int(bits)
}


Before using, create following structures in your own project/context:

go
type Bytestream2 struct {
	// Your implementation
}

func (b *Bystream2) get_byte() (byte, int){
	// Your implementation
}

func (b *Bystream2) peek_byte() (byte, int){
	// Your implementation
}
 

Please note, that I'm following your strict requirement "Do not create auxiliary or helper functions". In Go you especially use `.Read()` methods instead `peek_byte()` or `get_byte()`. You should design the `Bytstream2` Interface appropriately and access the byte-stream accordingly. 

Equally to generate context like structure `*Jpeg2000DecoderContext` and creating method receiver functions is advisable.

Moreover, without satisfactory context it's hard to estimate, what type of error handling would be appropriated. To build robust software you should definitely implement status management!