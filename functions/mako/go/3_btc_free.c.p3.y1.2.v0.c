import "os"

func btc_free(ptr *interface{}) {
  if ptr == nil {
    os.Exit(1) // similar to abort()
    return
  }

  ptr = nil
}