package main

import (
	"encoding/binary"
	"errors"
)

type arrayReader struct {
	arr []byte
}

func (a *arrayReader) Read(p []byte) (n int, err error) {
	n = copy(p, a.arr)
	a.arr = a.arr[n:]
	if len(a.arr) == 0 {
		err = errors.New("end of array")
	}
	return
}

func btc_uint32_read(zp *uint32, xp *[]byte, xn *int) bool {
	if *xn < 4 {
		return false
	}

	ar := arrayReader{arr: *xp}
	err := binary.Read(&ar, binary.BigEndian, zp)
	if err != nil {
		panic(err) // error handling here
	}

	*xp = ar.arr
	*xn -= 4

	return true
}