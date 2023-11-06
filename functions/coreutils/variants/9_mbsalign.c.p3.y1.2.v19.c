In order to rewrite the `mbsalign` function from C to a Go function, a few things have to be modified:

- Go has built-in unicode support, so there's no need for so many checks related to unibyte/multibyte scenario. The equivalent we have to work around in Go is delivering bytes and/or runes.  
- In particular, there might not be a direct semantically equivalent implementation from the received code to Go due to Go UTF-8 native support in strings.
- Go does not have reference parameters, a workaround needs to be employed for this. The implementation is free of panic errors. 

Check the translated function in Go below:

go
type Align int

const (
	Left Align = iota
	Right
	Center
)

func MbsAlign(src string, destSize int, width int, align Align, flags int) (string, int, error) {

	dest := make([]rune, destSize)

	nCols := len([]rune(src))
	if nCols > width {
		nCols = width
	}
    
	nSpaces := 0
	if width > nCols {
		nSpaces = width - nCols
	}

	var endSpaces, startSpaces int
	switch align {
	case Left:
		startSpaces = 0
		endSpaces = nSpaces

	case Right:
		startSpaces = nSpaces
		endSpaces = 0

	case Center:
		startSpaces = nSpaces / 2
		endSpaces = startSpaces + nSpaces%2
	}

	if nSpaces == width {
		startSpaces = 0
		endSpaces = 0
	}

	
	// Padding required.
	spaces := width - nCols
	nStartSpaces := 0
	nEndSpaces := spaces

	switch align {
	case Left:
		nStartSpaces = 0
		nEndSpaces = spaces
	case Right:
		nStartSpaces = spaces
		nEndSpaces = 0
	case Center:
		nStartSpaces = spaces/2 + spaces%2
		nEndSpaces = spaces/2
	}

	if flags&MbaNoLeftPad != 0 {
		nStartSpaces = 0
	}
	if flags&MbaNoRightPad != 0 {
		nEndSpaces = 0
	}

	// Construct output string
	return strings.Repeat(" ", nStartSpaces) + src + strings.Repeat(" ", nEndSpaces), nCols, nil
}


You will need to define your flags outside of this function in limits that Go languages will accept for integer comparison and bitwise operations. Replace `MbaNoLeftPad` and `MbaNoRightPad` with the mapping of the flags you wish to implement.