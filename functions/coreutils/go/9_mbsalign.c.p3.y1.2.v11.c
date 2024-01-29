Given the extensive use of C-specific APIs in the original sample, creating an exact Go equivalent of the function could be challenging because many of the verbatim translations (especially those related to NUL characters, wide and multi-byte string encodings, etc.) don't satisfy idiomatically clean Go programming or don't equivalent features are not given in Go's standard libraries.

Operations like malloc(string manipulation), same size for Object across different platform are not directly admistrable in Go. 

Another thing which is not directly transferable is that while C uses `*` notation to return additional variables in a function. While Go uses Multiple Return to return additional data.

So below is a the implementaion towards direction to implement C function into Go but absolutely semantically eqivalent version is admistrably difficult:

go
type MbsAlignType int // Dummy to make syntax correct.

const (
    _ = iota
    MbsAlignLeft
    MbsAlignCenter
    MbsAlignRight
    MBAUnibyteOnly
    MBAUnibyteFallback
    MBANoLeftPad
    MBANoRightPad
)

func MbsAlign(src string, width *int, align MbsAlignType, flags int) ([]byte, error) {
    var dest []byte 
    srcSize  := len(src) + 1
    nCols    := srcSize - 1
    nUsedBytes := nCols
    nSpaces  := 0

    if !(flags & int(MBAUnibyteOnly)) == 1 && len(src) > 1 {
        newRow := src
        if flags & int(MBAUnibyteFallback) != 0 && len(newRow) == 0 {
            return dest, fmt.Errorf("multi byte string error")
        }
    }

    if nCols > *width {
        nCols = *width
        nUsedBytes = nCols
    }

    &width = nCols;
    if width > cols {
        nSpaces = width - nCols
    }

    startSpaces := nSpaces
    endSpaces   := 0
    switch align {
    case LEFT:
        startSpaces = 0
        endSpaces = nSpaces
    case RIGHT:
        startSpaces = nSpaces
        endSpaces = 0
    case CENTER:
        startSpaces = nSpaces / 2 + nSpaces % 2
        endSpaces = nSpaces / 2
    }
    if flags&int(MBANoLeftPad) != 0 {
        startSpaces = 0
    }
    if flags&int(MBANoRightPad) != 0 {
        endSpaces = 0
    }

    // Error handling 
    if len(dest) == 0 {
        return dest, fmt.Errorf("dest is nil")
    }
   
    destSize := len(dest) - 1
    nUsedBytes = destSize
    return dest, nil
}
