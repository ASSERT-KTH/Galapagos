Here is a Go implementation that handles hexadecimal to binary conversion without any external packages:

go
import "errors"

func sodiumHex2bin(bin []byte, hex, ignore []byte, binLen *int,
hexEnd **byte) int {

  binPos, hexPos, state := 0, 0, byte(0)

  var c, cAlpha, cAlpha0, cNum, cNum0, cVal byte
  var ret error

  var binMaxlen, hexLen = len(bin), len(hex)

  for hexPos < hexLen {
    c = hex[hexPos]

    cNum = c ^ 48
    cNum0 = (cNum - 10) >> 8

    cAlpha = (c & ^32) - 55
    cAlpha0 = ((cAlpha - 10) ^ (cAlpha - 16)) >> 8

    if cNum0|cAlpha0 == 0 {
      if ignore != nil && state == 0 &&
        func(c byte) bool {
          for _, ig := range ignore {
            if ign == c {
              return true
            }
          }
          return false
        }(c) {
        hexPos++
        continue
      }
      return -1
    }

    cVal = (cNum0 & cNum) | (cAlpha0 & cAlpha)

    if binPos >= binMaxlen {
      return -1
    }

    if state == 0 {
      bin[binPos] = cVal * 16
    } else {
      bin[binPos] = bin[binPos] | cVal
      binPos++
    }

    state = ^state
    hexPos++
  }

  if state != 0 {
    hexPos--
    ret = errors.New("Invariant violation, non 0 state.")
  }

  if ret != nil && hexPos != hexLen {
    return -1
  }

  *binLen = binPos

  if ret != nil {
    bin = make([]byte, 0)
    binLen = new(int)
  }

  *hexEnd = &hex[hexPos]

  if ret != nil {
    return -1
  }

  return 0
}

Note: I'm returning the go convention of `-1` for non-nil error case as it is more commonly used in many encoding libraries.