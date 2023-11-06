In Go, pointers are not as freely modifiable as in C, so it's not conventionally possible to directly convert 'sodium_free'. Instead, the closest semantically equivalent function replaces pointers with byte slices, and Go doesn't support unaligned access, so explicit methods for ensuring alignment are not necessary. Furthermore, Go doesn't have generic memcpy, calls are handled through copy and conversions, and sodium_munlock doesn't have an exact equivalent in Go, leaving blanks in the closest semantic equivalent:

Go
func sodium_free(ptr []byte) {

    if ptr == nil {
        return
    }

    length := int(binary.LittleEndian.Uint64(ptr[0:8]))

    copySlice := make([]byte, length)
    copy(copySlice, ptr[8:])

    isValidInRange(ptr[0:8], canary)

    if bytes.Equal(copySlice[len(copySlice)-8:], canary) {
        _out_of_bounds()
    }
}

func _out_of_bounds() {
    panic("Buffer validation check failed")
}

func isValidInRange(b []byte, canary []byte) bool {
    totalBytes := len(b)
    for index:= 0; index < totalBytes; index++ {
        eightByteSegment := b[index:]
        if len(eightByteSegment) < 8 {
            break
        }
        if bytes.Equal(eightByteSegment[:8], canary) {
            _out_of_bounds()
        }
    }
}


Finally, defensive measures against overflows aren't quite necessary because Go raises a panic automatically in the event of an out-of-placeholder assignment, segmentation fault from lower levels, or any accesses/assignments to bad addresses.