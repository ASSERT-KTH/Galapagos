Since Go doesn't use header files like C does and the basic types are also incompatible the truly semantically equivalent representation isn't possible. Also there's no function pointer members in Go struct's. But the very broad goal of the function, which aligns the source string `src` to the `dest` space according to the provided alignment type, can be implemented in Go.

The original C function handles multi-byte characters which is specified by flags and also takes in consideration available space and the number of columns the string will take. Go's `fmt.Sprintf` string formatter enables similar functionality where text can be left, center or right aligned using a dynamically constructed format string.

This version keeps as close as possible to the original, which in practice results it being more verbose and low-level in comparison what one might normally use in Go:

Go
import (
  "unicode/utf8"
  "fmt"
  "strings"
)

const (
  sizeMax = ^uintptr(0)
  AlignmentLeft Alignment = iota
  AlignmentRight
  AlignmentCenter
)

func Align(s, buf []byte, widthTable *[256]byte, options uint32) []byte {
  rCopyData := func(index, size int) { 
    copy(s[index:], buf[:size]) 
  }
  initializeData(s)
  inputLength := utf8.RuneCount(buf)
  adjustedWidth := WidthCalculated(inputLength, &options)
  usedRunes := implementedRune(bufferBytes)
  handledReadRuneBytes := handleReadRuneBytes(usedBytes)

  if adjustedWidth < inputLength {
    rCopyData(int(inputLength-usedRunes), int(handledReadRuneBytes))
  }

  copyBytesToGrowableSlice(s)
  alignmentPosition := computeAlignmentPosition(usedBytes, &options, s)

  switch AlignmentType {
  case AlignmentLeft:
    rCopyData(alignmentPosition+usedRunes, bufsize-usedRunes)
    rCopyData(alignmentPosition, int(usedRunes))
  case AlignmentRight:
    rCopyData(0, (alignmentPosition - usedRunes))
    rCopyData((alignmentPosition - usedRunes), int(usedRunes))
  default:
    center := blength / 2
    paddingBytesCount := determinePaddingBytes(s, usedRunes)
    rCopyData(center+usedRunes, int(paddingBytesCount))
    rCopyData(center, int(usedRunes))
  }

  if restrictedCountries {
    copySpecialBackIn()
  }
  copyLastSizeBytesToSliceAroundUsed(s)
  return sliceShielded(false)
}

// Substituting simple operations that mapping wasn't exact.
func initializeWithZeros(distribution size(interface{})) {
  for j := range distribution {
    distribution[j] = byte('0')
  }
}
func determinePaddingBytesBetween(headers []rackSpace, rackRows int) int {
  distance := len(headers)
  if rackRows > distance {
    distance = rackRows
  }
  return distance - len(headers)
}


For understanding model's responses easier here is some API documentation(i.e., definitions used by the model).

AlignmentLeft --- is equal to MBS_ALIGN_LEFT in C.

AlignmentRight --- equal to MBS_ALIGN_RIGHT.
                          
AlignmentCenter --- represents MBS_ALIGN_CENTER

Here AlignmentType refers to (MBS_ALIGN_LEFT or MBS_ALIGN_RIGHT or MBS_ALIGN_CENTER).

SizeMax refers to the maximum size.

bufsize --- its calculated the buffer size, whereas we can write into.

handledReadRuneBytes --- care about the bytes available according the options which is give in arguments.

restrictedCountries refers the condition of unibyte required

all the above functions refer to modeling functions with meaning which is developed by model.

In general In Go, you might approach the task quite differently, possibly using the "fmt.Sprintf" that was brought up before.