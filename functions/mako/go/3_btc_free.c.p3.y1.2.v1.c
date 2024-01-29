import "os"

func btc_free(ptr *interface{}) {
	if ptr == nil {
		os.Exit(1)
	}

	ptr = nil
}