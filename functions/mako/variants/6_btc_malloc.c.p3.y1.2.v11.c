import (
	"log"
	"os"
)

func btc_malloc(size int) []byte {
	ptr := make([]byte, size)
	
	if ptr == nil {
		log.Panic("Memory allocation failed.")
		os.Exit(1)
	}

	return ptr
}