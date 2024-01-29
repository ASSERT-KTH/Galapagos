go
import (
	"errors"
)

func sodiumBin2Hex(hex *[]byte, hexMaxLen int, bin *[]byte, binLen int) (*[]byte, error) {
	if binLen >= 1<<31-1 || hexMaxLen <= binLen*2 {
		return nil, errors.New("sodium_misuse")
	}
	
	for i := 0; i < binLen; i++ {
		c := (*bin)[i] & 0xf
		b := (*bin)[i] >> 4
		x := ((87 + c + ((c - 10) >> 8) & ^38) << 8) |
			(87 + b + ((b - 10) >> 8) & ^38)

		(*hex)[i*2] = byte(x)
		x = x >> 8
		(*hex)[i*2+1] = byte(x)
	}
	(*hex)[binLen*2] = 0

	return hex, nil
}

This Go function is as equivalent as possible, with inevitable adjustments for Go style, behavior, and error management conventions. The function signature takes pointers to a byte slice as inputs due to its requirement to modify the input values equivalent to the behavior in the C code. However, Go does not allow constant bitwise and arithmetic operations on byte type directly similar to 'C'. Adjustments have been made to account for these differences. An error is returned when misuse is detected so it's in line with customary Go design principles, which prioritize proper error handling over failing quietly or panicking. Finally, the return statement returns the hex pointer for continued use in following operations.