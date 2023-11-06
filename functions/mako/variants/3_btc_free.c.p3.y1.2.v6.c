go
import "C"
import "log"

func btc_free(ptr *C.void) {
  if ptr == nil {
    log.Fatal("Pointer is nil")
  }
  
  C.free(ptr)
}
