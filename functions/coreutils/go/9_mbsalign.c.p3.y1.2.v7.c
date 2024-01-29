As you may know, it's not possible to directly translate this piece of code from C to Go without knowing all the auxiliary functions (such as mbstowcs, wc_ensure_printable, wcswidth, etc.) and even the definition of the non-standard C library call mbstowcs. However, I will do my best to provide the closest equivalent in Go. But consider that you might need to substitute or implement some parts of code accordingly.

go
import (
    "errors"
    "fmt"
    "unicode/utf32"
    "unicode/utf8"
)

const (
    flagMbaUnibyteOnly     = 0x01
    flagMbaUnibyteFallback = 0x02
    flagMbaNoLeftPad       = 0x08
    flagMbaNoRightPad      = 0x10

    alignLeft   = 0
    alignRight  = 1
    alignCenter = 2
)

func mbsalign(src string, dest []rune, destSize uint64, width *uint64, align int, flags int) (uint64, error) {
    const SIZE_MAX uint64 = ^uint64(0)

    ret := SIZE_MAX
    srcSize := uint64(len(src))

    var newstr string
    var strToPrint string = src
    var strWc []rune

    var nCols uint64 = srcSize
    var nUsedBytes uint64 = nCols
    var nSpaces uint64 = 0
    var conversion bool = false
    var wcEnabled bool = false

    if !(flags&flagMbaUnibyteOnly) != 0 && utf8.UTFMax > 1 {
        strWc = []rune(src)
        wcEnabled = true
        fmt.Println("Detail functions should be implemented regarding your business and project requirements")
        // conversion = wcEnsurePrintable(strWc);
    }

    if wcEnabled && (conversion || (nCols > *width)) {
        newstr = string(strWc[:*width])
        strToPrint = newstr
        nCols = *width
        nUsedBytes = uint64(len(newstr))
    }

    if nCols > *width {
        nCols = *width
        nUsedBytes = nCols
    }

    if *width > nCols {
        nSpaces = *width - nCols
    }

    *width = nCols

    var startSpaces, endSpaces uint64
    switch align {
    case alignLeft:
        startSpaces = 0
        endSpaces = nSpaces
    case alignRight:
        startSpaces = nSpaces
        endSpaces = 0
    case alignCenter:
        startSpaces = nSpaces / 2
        endSpaces = nSpaces - nSpaces/2
    default:
        return 0, errors.New("invalid alignment")
    }

    if flags&flagMbaNoLeftPad != 0 {
        startSpaces = 0
    }
    if flags&flagMbaNoRightPad != 0 {
        endSpaces = 0
    }

    if destSize != 0 {
        dest = append(dest, strWc[:nUsedBytes]...)
        for i := uint64(0); i < endSpaces; i++ {
            dest = append(dest, ' ')
        }
    }

    ret = nUsedBytes + startSpaces + endSpaces

    return ret, nil
}
 
I tried my best to keep the semantics close in C & Go but Go is UTF-8 based. So, some functions regarding conversions are unnecessry in Go and also Go doesn't utilize any flags unlike C. You might need some tweeks in these flags and also on mbstowcs (multibyte to wides string copy) functions similar behavior in Go. Other points should be taken in account regarding your exact requirements.  Nothing is mentioned about error management neither business flow is clear. So better practices might be applied when it's clear. Here is the an study related with Go & C representation you may refer.
[https://stackoverflow.com/questions/48005524/convert-c-string-to-go-string]