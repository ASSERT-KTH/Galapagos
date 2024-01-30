Here is the equivalent code in Go:

go
import (
	"errors"
)

func sodiumMalloc(size int) ([]byte, error) {

    if size < 0 {
        return nil, errors.New("Size cannot be less than 0")
    }

    ptr := make([]byte, size)

    for i := range ptr {
    	ptr[i] = garbageValue
    }

    return ptr, nil
}


Few things to remember:

1) In Go, we don't have `malloc` therefore equivalent is using a Go slice of `bytes` that size you want and you will get a zero value array of that size. Zero value of `byte` is `0`

2) In `Go` there's no `NULL` therefore in case `malloc` fails, we return an `error`

3) Instead of using memset to fill the slice with garbageValues, using a simple loop in Go because there's no exact equivalent of `memset` available in built in `Go` standard library

Note:  Please replace `garbageValue` with your value.