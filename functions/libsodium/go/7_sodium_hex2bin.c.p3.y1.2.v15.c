Go doesn't support multiple return values or non-integer error codes like C.Try using the error type for return values.

func SodiumHex2bin(bin []byte, binMaxLen int,
hex string, hexLen int, ignore string, binLen *int, hexEnd *int) (int, error) {
var binPos int
var hexPos int
var ret int
var c byte
var cAcc byte 
var cAlpha0, cAlpha byte 
var cNum0, cNum byte 
var cVal byte 
var state byte 

for hexPos < hexLen {
  c = hex[hexPos]
  cNum = c ^ 48
  cNum0 = (cNum - 10) >> 8
  cAlpha = (c &^ 32) - 55
  cAlpha0 = ((cAlpha - 10) ^ (cAlpha - 16)) >> 8    
  if cNum0 | cAlpha0 == 0 {
    if ignore != "" && state == 0 && strings.IndexByte(ignore, c) != -1 {
      hexPos++                
      continue
    }
    return binPos, errors.New("c_num0 | c_alpha0 is zero")
  }
  cVal = (cNum0 & cNum) | (cAlpha0 & cAlpha)
  if binPos >= binMaxLen {
    return ret, errors.New("binPos greater or equal to binMaxLen")  
  }
  if state == 0 {
    cAcc = cVal * 16   
  } else {
    bin[binPos] = cAcc | cVal
    binPos++
  }
  state = ^state
  hexPos++
}     

if state != 0 {
  hexPos--
  ret = -1
}
if ret != 0 {
  binPos = 0
}

*hexEnd = hexPos

if hexPos != hexLen {
  ret = -1  
}

*binLen = binPos

return ret, nil 
}