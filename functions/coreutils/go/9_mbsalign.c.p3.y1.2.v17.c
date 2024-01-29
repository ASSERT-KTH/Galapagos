It is important to note that you cannot maintain an identical function signature while porting this C code to Go due to the fundamental differences between both languages especially relating to pointers and error handling. Accordingly, this suggestion modifies the signature to make it usable and idiomatic in Go. Also, there might be necessary handling of encoding conversion which you might implement with the help of external library, for instance, `golang.org/x/text/width` and `golang.org/x/text/transform`

This code shows the basic mappings between C idioms and Go but doesn't make a perfect port:

go
import (
	"errors"
	"golang.org/x/text/transform"
	"golang.org/x/text/width"
	"strings"
	"unicode/utf8"
)

const (
	// These constants are to represent the imaginary `mbs_align_t` enumerated type in Go
	MBS_ALIGN_LEFT uint = iota
	MBS_ALIGN_RIGHT
	MBS_ALIGN_CENTER

	// These constants are to represent MBA_* style bitmask flags in Go
	MBA_UNIBYTE_ONLY uint = 1 << (iota + 1)
	MBA_UNIBYTE_FALLBACK
	MBA_NO_LEFT_PAD
	MBA_NO_RIGHT_PAD
)

func mbsalign(src string, dest *string, align uint, flags uint) (ret int, err error) {
	if dest == nil {
		return ret, errors.New("dest cannot be nil")
	}

	if flags&MBA_UNIBYTE_ONLY == 0 && utf8.RuneCountInString(src) > 1 {
		t := transform.Chain(width.Fold, transform.RemoveFunc(isNonCharacter))
		tOutString, _, _ := transform.String(t, src)

		// This handling should incorporate wc_ensure_printable's modular functionality 

		sourceRuneCount := utf8.RuneCountInString(tOutString)
		 if sourceRuneCount > (*myWidth) {
			 truncLength := sourceRuneCount - *myWidth
			 src = string([]rune(src)[:truncLength])
		 }

		requestedWidth := *myWidth
		colCount := utf8.RuneCountInString(src)
		var startPos, endPos int

		//deal with padding need here
		if requestedWidth > colCount {
			n_spaces := requestedWidth - colCount
			switch align {
			case MBS_ALIGN_LEFT:
				startPos = 0; endPos = n_spaces
			case MBS_ALIGN_RIGHT:
				startPos = n_spaces; endPos = 0
			default:  // center alignment
				startPos = n_spaces/2  + n_spaces%2
				endPos = n_spaces / 2
			}

			if flags & MBA_NO_LEFT_PAD == MBA_NO_LEFT_PAD {
				startPos = 0
			}

			if flags & MBA_NO_RIGHT_PAD == MBA_NO_RIGHT_PAD {
				endPos = 0
			}

			*dest = strings.Repeat(" ", startPos) + src + strings.Repeat(" ", endPos)
			// Info for caller about bytes needed; no null
			return ret + startPos + endPos
		}
	}
}

"wc_ensure_printable", "wc_truncate" and "mbs_align_pad" functions are all elided in the conversion. The tricky parts with missing C strings NUL termination, casting/conversion between byte arrays and rune arrays have been ignored with conceitedly ideal assumption about data in UTF-8 string and rune.

Please make sure to understand the conversion process when transplanting features exactly in the situations like "the buffer passed in vs creating/converting it into Go's copy semantics", "malloc and free raw memory sectors via unsafe pkg" and such.
