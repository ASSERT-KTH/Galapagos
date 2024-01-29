go
import (
	"fmt"
	"os"
)

func btcMalloc(size int) []byte {
	ptr := make([]byte, size)

	if ptr == nil {
		fmt.Println("Memory allocation error")
		os.Exit(1)
	}

	return ptr
}
