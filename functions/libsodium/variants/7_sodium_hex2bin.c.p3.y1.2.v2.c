The following Go code translates the given C code as closely as possible while maintaining semantic correctness according to the rules of Go:

go
func sodiumHex2bin(bin *[]byte, binMaxLen uint64, hex *string, hexLen uint64, 
                   ignore *string, binLen *uint64, hexEnd *uint64) int {

    binPos  : uint64 = 0
    hexPos  : uint64 = 0
    ret     := 0
    var c   : byte
    var cAcc: byte = 0
    var cAlpha0, cAlpha: byte
    var cNum0, cNum: byte
    var cVal: byte
    var state: byte = 0

    for hexPos < hexLen {
        c        = (*hex)[hexPos]
        cNum    = c ^ 48
        cNum0   = (cNum - 10) >> 8
        cAlpha  = (c &^ 32) - 55
        cAlpha0 = ((cAlpha - 10) ^ (cAlpha - 16)) >> 8
        if cNum0 | cAlpha0 == 0 {
            if ignore != nil && state == 0 && strings.Contains(*ignore, string(c)) {
                hexPos++
                continue
            }
            break
        }
        cVal = (cNum0 & cNum) | (cAlpha0 & cAlpha)
        if binPos >= binMaxLen {
            ret   = -1
            break
        }
        if state == 0 {
            cAcc = cVal * 16
        } else {
            (*bin)[binPos] = cAcc | cVal          
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
    if hexEnd != nil {
        *hexEnd = hexPos
    } else if hexPos != hexLen {
        ret = -1
    }
    if binLen != nil {
           *binLen = binPos
    }
    return ret
}


Please note that Go doesn't consider variable types like `size_t` and `unsigned char`, instead it uses `uint64`  for representing non-negative integer with 64 bits and `byte` for uint8, unsigned 8-bit integers respectively which comes closest to semantic type of problem's C code. Also, it doesn't have any direct equivalent to C++'s `errno'. The equivalent behaviour needs be implemented by manually checking and handling errors in Go.