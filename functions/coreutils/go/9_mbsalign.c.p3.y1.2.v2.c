It's worth noting that there is no direct equivalent in the Go language for this C function. The `mbsalign` function aligns and truncates a multibyte string to fit within the specified width and alignment, and deals with special multi-byte string formats in the way it does.

As we can observe, Go language will not handle the case with special print character conversion and also we have difference in errors types/interface. Due Golang does not fully support handling of byte-wide representation multi-byte characters, we will need to approximate and implement a simpler unibyte function.

Please find the simple analogue of aligning function in Go below. However, it doesn't have Unicode improvement for width measuring, conversion to a wide-format and shifting destination to accommodate padding calculation since Go doesn't interacts with memory as direct as C does.

go
import "strings"

type MbsAlign int

const (
  MBS_ALIGN_LEFT MbsAlign = iota
  MBS_ALIGN_RIGHT
  MBS_ALIGN_CENTER
)

const MBA_UNIBYTE_ONLY = 1
const MBA_NO_LEFT_PAD = 2
const MBA_NO_RIGHT_PAD = 4

func MbsAlign(src string, size int, width *int, align MbsAlign, flag int) (string, int) {
  var alignFunk func(int, string) string
  
  switch align {
  case MBS_ALIGN_LEFT:
    alignFunk = strings.Repeat
  case MBS_ALIGN_RIGHT:
    alignFunk = func(n int, s string) string { return strings.Repeat(s, n) + src }
  case MBS_ALIGN_CENTER:
    alignFunk = func(n int, s string) string { return strings.Repeat(s, n/2) + src + strings.Repeat(s, n-n/2) }
  }

  var startSpaces, endSpaces int

  var nSpaces int = *width - len(src)

  if len(src) > *width {
    nSpaces = 0
    src = src[:*width]
  }

  switch align {
  case MBS_ALIGN_LEFT:
    *width = len(src)
    startSpaces = 0
    endSpaces = nSpaces
  case MBS_ALIGN_RIGHT:
    startSpaces = nSpaces
    endSpaces = 0
  case MBS_ALIGN_CENTER:
    startSpaces = nSpaces / 2
    endSpaces = nSpaces - startSpaces
  }

  if flag & MBA_NO_LEFT_PAD > 0 {
    startSpaces = 0
  }

  if flag & MBA_NO_RIGHT_PAD > 0 {
    endSpaces = 0
  }

  dstSize := len(src) + startSpaces + endSpaces

  if dstSize > size {
    dstSize = size
  }

  result := alignFunk(nSpaces, " ")

  return result, dstSize
}

Please note that the Go's Unicode libraries could be used further for proper processing multibyte characters.