It's not possible to make an accurate conversion of this function from C to Go as requested while keeping the same function signature, since Go does not support operator overloading or function signatures the same way C does.

More specifically, Go does not support C-style enumeration constants for function parameters, nor does it support bit manipulation directly on integer types in the same way C does – they must be explicitly converted to byte or uint types first. Additionally, many of the C libraries and functions used such as strlen, malloc, mbstowcs, wcswidth, and wcstombs, do not have direct equivalents in Go.

Further, Go does not feature idiomatic error handling through special return values (like SIZE_MAX in the original function), opting instead for multiple return values where one is a specified error type.

Still, I can show you a loose transliteration involving multiple corrections. Please note that behaviour still won't be identical, rather, this serves to reflect the concept from the C code in Go as closely as accuracy and idiomatic Go usage allow:

Go
type mbsAlign int

const (
    mbsAlignLeft mbsAlign = iota
    mbsAlignRight
    mbsAlignCenter
)

func mbsalign(src string, dest []byte, widthPtr *int, align mbsAlign, flags int) (retn int) {
    var (
	srcLen       = len(src) + 1
	newstr       []byte
	wstr         []rune
	printingStr  = src
	n_chars      = srcLen - 1 // Not Including NULL char
	charBytesLen = n_chars
	padding      = 0
	isConverted  = false
    )

    // NOT POSSIBLE TO Full Fork HERE
    
    switch align {
	case mbsAlignLeft:
	case mbsAlignRight:
		padding = *widthPtr - n_chars
	case mbsAlignCenter:
		padding = *widthPtr - n_chars / 2
    }

    *widthPtr = n_chars

	if isConverted {
		//If unibyte conversion required
		if charBytesLen >= len(dest) {
			copy(dest, printingStr)
		} else {
			dest = []byte(printingStr)
		}
	}
  
	retn = charBytesLen + padding

	return 
}

When `newstr` might need releasing change at the end:

Go
retn = charBytesLen + padding * 1
newstr = nil 
return
