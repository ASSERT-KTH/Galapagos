The given function `sodium_hex2bin` in C does not have direct equivalents in Go. Certain concepts in the below C function like pointer manipulation and certain bitwise operations are handled very differently in Go. 
Moreover, Go, being a safe language, doesn't allow manipulation of individual bits of characters and pointer arithmetics as C does. 

One basic equivalent is linke below, but without pointers and without error manipulation. Which are primarily supported by go as errors and not as pointer to be changed and returned or starting from a place in string.

go
func sodiumHex2bin(hex string, ignore string) (string, error) {
	var bin string
	var c byte
	var state byte

	hexRunes := []rune(hex)
	for ix := 0; ix < len(hexRunes); ix++ {
		c = byte(hexRunes[ix])
		cNum := c ^ 48
		cNum0 := (cNum - 10) >> 8
		cAlpha := (c &^ 32) - 55
		cAlpha0 := ((cAlpha - 10) ^ (cAlpha - 16)) >> 8
		if (cNum0 | cAlpha0) == 0{
			if len(ignore) != 0 && state == 0 && strings.Contains(ignore, string(hexRunes[ix])) {
				continue
			}
			break
		}
		cVal := (cNum0 & cNum) | (cAlpha0 & cAlpha)
		if state == 0{
			state = cVal * 16

		} else {
			bin += string(state | cVal)
			state = 0
		}
	}
	return bin, nil
}
 

Note the lack of error handling and the use of point locations since it's different in Go. The equivalent Go approach would be adding it to the function's return like `(str, error) {return..., err}` approach or such. You'll have to chose one format or the other, There really isn't a like and like conversion guaranteed. And error numbers isn't simply a case of overwriting the error integer 'errno. It's returned as part of error mechanism.