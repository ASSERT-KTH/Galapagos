Go does not support direct calculation of byte sizes nor has an equivalent method like av_mallocz. This is a system level operation that is abstracted from Go standard library. Also, instead of returning a pointer to a region of memory, Go encourages the use of slices, which keep track of the length and capacity of sequences of elements in memory.

How an equivalent function would work in Go cannot be presented exactly, but this is the closest it can get:

Go
import "errors"

func avCalloc(nmemb int, size int) ([]byte, error ) {
	var result int
	multErr := sizeMult(nmemb, size, &result)
	if multErr != nil {
		return nil, errors.New("multiplication error")
	}
	newSlice := make([]byte, result)
	return newSlice, nil 
}

Here it returns a byte slice instead of a pointer and introduces error type for improper cmemb*size multiplications. But this would fundamentally work like the `av_calloc` function by returning a block of initialised memory.