go
import "os"

func btcFree(ptr interface{}) {
    if ptr == nil {
        os.Exit(1) // this is equivalent to `abort()`
    }
    // The Go garbage collector handles memory release, unlike C
}
