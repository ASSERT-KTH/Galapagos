Here's how you could implement this function in a semantically equivalent way using Go:

Go
func avio_wb32(s *AVIOContext, val uint32) {
    s.avio_w8(byte(val >> 24))
    s.avio_w8(byte(val >> 16))
    s.avio_w8(byte(val >> 8))
    s.avio_w8(byte(val))
}


Please note that this assumes a method `avio_w8` defined on the pointer to `AVIOContext`. You may have to adjust this code according to the actual definition of `AVIOContext` and its associated methods.
On a side note, letter case matters for visibility of names in Go. In Go, a name is exported if it begins with a capital letter. When importing a package, you can refer only to its exported names. Every go source file is part of some package, and every package is a shared namespace s anything on a file depends on where it has been declared. Keeping these go conventions in mind, a more idiomatic version of this function in go goes like

Go
func (s *AVIOContext) WB32(val uint32) {
    s.W8(byte(val >> 24))
    s.W8(byte(val >> 16))
    s.W8(byte(val >> 8))
    s.W8(byte(val))
}
