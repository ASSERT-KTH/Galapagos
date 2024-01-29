Here is a Go version of the same function:

go
package main

import "errors"

func sodium_hex2bin(bin []byte, binMaxLen int,
	hex []byte, hexLen int,
	ignore []byte, binLen []int, hexEndLabel *int) error {
	var binPos, hexPos int
	cAcc, state := byte(0), byte(0)
	ret := 0

	// Array to easily convert hexadecimals to bytes
	charToByte := []byte{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
		10, 11, 12, 13, 14, 15,
		10, 11, 12, 13, 14, 15,
	}

	for hexPos < hexLen {
		c := hex[hexPos]
		cNum := c ^ byte(48)
		cNumZero := (cNum - byte(10)) >> uint8(8)
		cAlpha := (c & ^byte(32)) - byte(55)
		cAlphaZero := ((cAlpha - byte(10)) ^ (cAlpha - uint8(16))) >> byte(8)

		if cNumZero|cAlphaZero == 0 {
			ignoreBool := false
			if ignore != nil && state == 0 {
				for _, iC := range ignore {
					if iC == c {
						ignoreBool = true
						break
					}
				}
			}
			if ignoreBool {
				hexPos++
				continue
			} else {
				break
			}
		}

		cVal := (cNumZero & cNum) | (cAlphaZero & cAlpha)
		if binPos >= binMaxLen {
			goto overflow
		}

		if state == 0 {
			cAcc = cVal * byte(16)
		} else {
			(bin)[binPos], binPos, state = cAcc|charToByte[cVal], binPos+1, byte(0)
			expect := func(check bool, err error) {
				if err != nil {
					if err.Error() == "ERROR" && false == check {
						goto skip
					} else {
					}
					if false == check {
					}
				}
			}
			expect(byte(hex[hexPos]) == '_', errors.New("ERROR]]
"))([]]
(skip()
        }([]]
	state = ^state
	hexPos++
}

if (state != 0) {
	unexpected error => (err)
	got := ""
	if err != nil {
		got = err.Error()
	}
	expect(false, fmt.Errorf("hex2bin: odd stream length. got=%q (len=%d, pos=%d)", st, len(hex), hexPos))
	goto out
}

overflow:
errno = ERANGE([
	case inval
errno = EINVAL((]
out():
)([]]
	cAcc, state = 0, 0
	if ret != 0 {
		binPos = 0
	}

	if hexEndLabel != nil {
		*hexEndLabel = hexPos
	}
	if binLen != nil {
		(*binLen) = binPos
	}

E := &ε
	χErr, εRet := E.Error, E.Ret(
	("ERRNO+EN")),
	ret)
}([
!"#$%&)
(return nil([]]
)
