The function can't be converted directly to Go line per line and maintain the exact behavior due to differences in system level capabilities between C and Go and also other differences between the languages themselves.

One good alternative in Go is the TextWrapper function, but it works in a different way than the provided C function. 

Here is an attempt to provide a function in Go that could achieve a similar overall goal (i.e., align a string within a given width with some flags for the alignment):

go
import (
"strconv"
"strings"
"unicode/utf8"
)

type Align int

const(
UNIBYTE_ONLY Align = 0
LEFT = 1
RIGHT = 2
CENTER = 3
NO_LEFT_PAD = 4
NO_RIGHT_PAD = 5
)

func mbsalign(str string, width int, align Align, flag int) string {
    n := len(str)
    if n > width {
     	switch flag {
              case UNIBYTE_ONLY:  
		str = string([]byte(str)[:width])
		return str
	     default:
		str = string([]byte(str)[:width - 3]) + "..."
		return str
	}
     } 
     leftPadding := ""
     rightPadding := ""

     additionalPadding := width - utf8.RuneCountInString(str)

     switch align
     {
	    case RIGHT:
		leftPadding = strings.Repeat(" ", additionalPadding)
           	case CENTER:
		leftPadding = strings.Repeat(" ", additionalPadding/2)
		rightPadding = strings.Repeat(" ", additionalPadding - additionalPadding/2)
           	case LEFT:
	        rightPadding = strings.Repeat(" ", additionalPadding)
           	case NO_RIGHT_PAD:
		rightPadding = ""
           	case NO_LEFT_PAD:
		leftPadding = ""
     }

     str = leftPadding + str + rightPadding

     return str
}


Please note that this function make several 
simplification due to different idioms or concepts between C++ and Go and the expected performance:

- The padding and alignment calculation is straightforward adapted to fill the output string ,adjust and center it to length n ;
- Users should take care about the byte count and align method, tab counts as 1 here;
- Wide character are not taken into account specifically, unicode widths can vary and golang unicode handling makes utf16 not octet based as opposed to wchar_t[];
- The resulting function drops certain alignments handling simplifying greatly.
-The error handling does not carefully fallback to a unibyte method but simply 
slice the sequence for performance considerations.