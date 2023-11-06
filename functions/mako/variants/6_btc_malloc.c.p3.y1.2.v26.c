go
import (
	"log"
	"unsafe"
)

func btcMalloc(size uintptr) unsafe.Pointer {
	ptr, err := calloc(1, size)
        
	if err != nil {
		log.Fatal(err)
	}
	return ptr
}

It's important to note that `unsafe.Pointer` and `calloc` are risky to use in Go due to safety guarantee issues. Alternative strategies like using slices or allocating memory block via the `make` function would be better. Use caution while using this approach.