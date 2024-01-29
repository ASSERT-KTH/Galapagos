import "os"

func btcFree(ptr *interface{}) {
	if ptr == nil {
		os.Exit(1)
	}

	ptr = nil
}