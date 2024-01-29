go
import (
	"log"
	"os"
)

// Similar concept with some changes due to different language syntax and features

func btcMalloc(size int) []byte {
	ptr := make([]byte, size)

	// in go the make never fails unlike the C malloc
	if ptr == nil {
		log.Fatal("Memory allocation failed")
		os.Exit(1)
	}

	return ptr
}
