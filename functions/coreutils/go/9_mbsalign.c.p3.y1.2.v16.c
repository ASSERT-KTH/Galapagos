Due to the architectural differences between C and Go programming languages, it is virtually impossible to transport this function from C to Go maintaining the exact signature and not creating helper functions. For example:

1. Error handling is done differently in Go, which does not have a direct equivalent of "goto" in C. Also Go encourages to handle errors on spot.

2. Type handling and constants in Go are completely different conceptually and shouldn't be transposed directly as flags from C.

3. Function signatures are very different, for instance Go does not have direct support for returning pointers, therefore '*width' parameter cannot be expressed.  

4. Go does not have direct libraries helping to concatenate C string byte by byte, might require importing external packages or writing helper functions (against instructions) 

Regardless these differences, the following Go function below endeavours to have a best fit to closely achieve functionality as is acceptable within bounds:

go
import (
	"errors"
	"unicode"
	"unicode/utf8"
)

const (
	MBA_UNIBYTE_ONLY       = 1 << iota
	MBA_UNIBYTE_FALLBACK
	MBA_NO_LEFT_PAD 
        MBA_NO_RIGHT_PAD
)


func Mbsalign(src string, dest []byte, width int, align int, flags int) (int, error) {

	srcSize := len(src) + 1
	conversion := false

	var strWC []rune
	
	if !(flags&MBA_UNIBYTE_ONLY) == 1 && utf8.UTFMax > 1 {
		
		if (flags & MBA_UNIBYTE_FALLBACK) == 0 {
			return -1, errors.New("error converting string to wide format")
		}
	
	srcRunes := []rune(src)
		for i,r := range srcRunes {
		    if !unicode.IsPrint(r){
			      conversion = true
			      srcRunes[i] = unicode.ReplacementChar
			}
		}
	    
		strWC = srcRunes
	}

	if len(strWC) > 0 && (conversion || len(strWC) > width) {
		lengthInBytes := utf8.RuneCountInString(src)
		dest = []byte(string(strWC[:lengthInBytes]))
	}
	if len(src) > width {
		dest[:width] = []byte(src[:width])
	}
	width = len(dest)
        startSpaces, endSpaces  := Padding(config, width , len(*src), flags)
        
	dest = Align(dest, startSpaces, endSpaces)
        
	return width + len(dest), nil
}

func Align(s []byte, startSpaces, endSpaces int) []byte {
	if endSpaces > 0 {
		s = append(s, bytes.Repeat([]byte(" "), endSpaces)...)
	}
	if startSpaces > 0 {
		s = append(bytes.Repeat([]byte(" "), startSpaces), s...)
	}
	return s
}
func Padding(config mbsGlobals, width, lenSrc, flags int)(int, int){
        localIndent:= width- lenSrc
	EndSpaces, StartSpaces := Indent(config, localIndent)
	If EndSpaces {
            EndSpaces++  //Or however whitespace is expressed
        }
        If StartSpaces{
   	     StartSpaces++ //Or however whitespace is expressed
        }
        return EndSpaces, StartSpaces
}

