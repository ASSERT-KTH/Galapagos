Since Go does not have a good mapping to 'Jpeg2000DecoderContext' struct in the code example that you provided, you might rather create the equivalent struct in Go that works pretty much the same using peek and next on the same Reader.

Consider the below equivalent go code:

go
type Jpeg2000DecoderContext struct {
	run     []byte
	index   int64
	bitmask byte
	b       byte
	r       *bytes.Reader
	bitIndex uint8
}


func (s *Jpeg2000DecoderContext) getByte() byte {
	byteData, _ := s.r.ReadByte()
	return byteData
}


func (s *Jpeg2000DecoderContext) getBits(n int) (res int) {
    
	for n--; n >= 0; n-- {
		res <<= 1
		if s.bitIndex == 0 {
			if s.getByte() != 0xff {
				s.bitIndex = 8
			} else {
				s.bitIndex = 7
			}
		}
		s.bitIndex--
        _, err := s.r.Peek(1)
		if err == nil {
			res |= int(s.b>>s.bitIndex) & 1
		} else {
			panic(err)
		}
	}
	return
}

Note that error handling in Go is a best practice and as such the above example does not cover all possible error cases for code simplicity. Please make sure to handle all errors based on your use-case in your actual codebase.