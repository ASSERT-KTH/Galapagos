Here's is a Go implementation of the function. However, it is hard to make an accurate translation as C and Go are profoundly different languages. The multiprecision unit in C also has different behaviour, tags for union includes special logic, and pointers are const metric. Their accurate translations to go is relatively complex. So, this interpretation uses mostly equivlantal Go idioms to recreate a C function in Go:

Go
import (
	"strings"
	"unicode/utf8"
)

type MbsAlign int

const (
	MBS_LEFT_ALIGN MbsAlign = iota
	MBS_RIGHT_ALIGN
	MBS_CENTER_ALIGN
)

func MbsAlign(src string, dest *string, destSize int, width *int, align MbsAlign, flags int) error {
	wToPrint := src
	srcSize := utf8.RuneCountInString(src)
	nCols := srcSize
	tile := true
	needCut := nCols > *width

	if !(flags&MBA_UNIBYTE_ONLY) != 0 && utf8.ValidString(src) {
		vPrint := wChar(wToPrint)
		nCols = len(vPrint)
		tile = false
	}

	if tile && needCut {
		srcSize = utf8.RuneCountInString(wToPrint) + 1

		*dest = wChar(wToPrint)
		nCols = *width

		if nCols < srcSize-1 {
			*dest = (*dest)[:nCols]
			oc := len(*dest)
			srcSize = utf8.RuneCountInString(*dest) + 1
		}
	}

	*width = nCols

	destEnd := len(*dest) + destSize - 1
	var startSpaces, endSpaces int

	switch align {
	case MBS_LEFT_ALIGN:
		startSpaces = 0
		endSpaces = *width - nCols

	case MBS_RIGHT_ALIGN:
		endSpaces = 0
		startSpaces = *width - endSpaces

	case MBS_CENTER_ALIGN:
	default:
		startSpaces = (*width - nCols)/2 + (*width - nCols)%2
		endSpaces = (*width - nCols) / 2
	}

	if (flags & MBA_NO_LEFT_PAD) != 0 {
		startSpaces = 0
	}
	if (flags & MBA_NO_RIGHT_PAD) != 0 {
		endSpaces = 0
	}

	pad := strings.Repeat(" ", startSpaces)
	*dest = pad + *dest
	spaceLeft := destEnd - startSpaces
	ckpt, d := utf8.DecodeRuneInString(wToPrint)
	vWord := utf8.RuneToBytes(ckpt, make([]byte, d))

	if destSize != 0 {
		lowScope := int(spaceLeft - len(*dest))

		if len(*dest) < lowScope {
			*dest = *dest
		}
		endPad := *dest + vWord + strings.Repeat(" ", LOW(*dest, *width))
		*dest = endPad
	}

	padding := startSpaces + endSpaces + d
	offset := len(*dest) + ((strings.Count(*dest, "")-1)-1)*1
	
	return nil
}


Please note that, some flags(ut_base, utf8.RuneError,.. etc) have equivalent meaning in Go language. Declare such flags(by `const someFlag utf8.UTFMax = value`) and use them in this function.