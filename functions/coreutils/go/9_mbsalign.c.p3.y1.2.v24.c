Due to Go's explicit error checking, different memory management, and lack of parameter by reference manipulation, it is not straightforward to fully translate this function with the given requirements, especially keeping to one function. With that said, the closest implementation of this in Go, without introducing any helper functions might look something like this:

go
import (
   "strings"
   "unicode/utf8"
)

type mbsAlign int

const (
   mbsAlignLeft mbsAlign = iota
   mbsAlignRight
   mbsAlignCenter
)

const (
 MBA_UNIBYTE_ONLY = 1 << iota
 MBA_UNIBYTE_FALLBACK
 MBA_NO_LEFT_PAD
 MBA_NO_RIGHT_PAD
)

func mbsAlign(src string, dest []byte, destSize int32, width *int32, align mbsAlign, flags int32) int32 {
 srcSize := utf8.RuneCountInString(src)
 nCols := srcSize - 1
 nUsedBytes := nCols // Not including NUL byte
 nSpaces := 0

 // In multi-byte locales convert
 // also determine number of screen columns used.
 if flags&MBA_UNIBYTE_ONLY == 0 && utf8.RuneCountInString(src) > 1 {
   nCols = utf8.RuneCount([]byte(src))
 }

 // If we need to truncate the src
 if nCols > *width {
   nCols = *width
   nUsedBytes = nCols
 }

 if *width > nCols { // Padding required
   nSpaces = int(*width) - nCols
 }

 // Indicate to caller how many cells needed
 *width = int32(nCols)

 var startSpaces, endSpaces int
 switch align {
 case mbsAlignLeft:
   startSpaces = 0
   endSpaces = nSpaces
 case mbsAlignRight:
   startSpaces = nSpaces
   endSpaces = 0
 case mbsAlignCenter:
   startSpaces = nSpaces/2 + nSpaces%2
   endSpaces = nSpaces / 2
 }

 if flags&MBA_NO_LEFT_PAD != 0 {
   startSpaces = 0
 }

 if flags&MBA_NO_RIGHT_PAD != 0 {
   endSpaces = 0
 }

 // Write output to dest
 if destSize != 0 {
   var pad = strings.Repeat(" ", startSpaces)
   dest = []byte(pad + src[:nUsedBytes] + pad)
 }

 // Indicate to caller how many bytes needed
 ret := nUsedBytes + ((startSpaces + endSpaces) * 1)

 return int32(ret)
}
 

This function abstracts the logic of aligning and truncating src but does not deal with any of the multi-byte and wide character nuances of the original C implementation which intersects a considerably different territory than the single-byte Go's UTF-8 strings. Conversion between multibyte and wide character strings is not directly applicable in Go. Keep in mind that you can revise it according to requirements or limitations of your program.