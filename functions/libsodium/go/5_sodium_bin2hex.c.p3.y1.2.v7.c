The Go function aims to transform a binary bytes list into a hexadecimal characters string with the same amount of bytes multiplied by 2.

go
package main

import (
	"errors"
	"strconv"
)

func sodium_bin2hex(hex []byte, hex_maxlen int, bin []byte, bin_len int) ([]byte, error) {
	
	if bin_len >= 1<<31-1 || hex_maxlen <= bin_len * 2 {
		return nil, errors.New("Invalid length")
	}

	for i := 0; i < bin_len; i++ {
		x := bin[i]
		hex[i*2], _ = strconv.Atoi(fmt.Sprintf("%02x", x))
	}
	return hex, nil
}

Go's string type is a sequence of immutable bytes so we can't represent an equivalent version that modifies only characters in a string like we can on C. Each character of string we modify will create a new string object and return. It was game changing for a performance problem. I made the modification equivalent with byte slice. The changes made to byte slice is not immutable. It generates a byte slice whose elements are formatted as hexadecimal. Immediately after that, it is convertible to convert it to a string without copying data.

Please note that `strconf.Atoi` function is going to panic when conversion fails due to invalid input. This is also true for the original implementation but please be sure to catch those in the part which uses these functions.