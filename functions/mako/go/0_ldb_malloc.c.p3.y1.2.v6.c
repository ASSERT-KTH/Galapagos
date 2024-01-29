go
import (
	"log"
	"os"
)

func ldb_malloc(size int) []byte {
	ptr := make([]byte, size)
	if ptr == nil {
		log.Println("Error: Allocation failed.")
		os.Exit(1)
	}
	return ptr
}

This implementation uses the Go builtin make function to allocate a slice of bytes of a given size. In case, if the memory allocation fails (which is highly unlikely and handled internally by the Go runtime, thus we don't explicitly need to check for it), we log this and exit the program with a failure code.