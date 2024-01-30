Unfortunately, creating an equivalent function signature to your provided `sodium_malloc` in Go language may not be completely possible. The Go language intentionally differs from C in various ways to improve simplicity, security, and readability. However, though not exact, I provided the closest function equivalent I could build in Go based on your request.

golang
import "bytes"

func SodiumMalloc(size int) []byte {
    if size <= 0 {
        return nil
    }
    garbageValue := byte(0)  // define your garbage value here
    buf := bytes.Repeat([]byte{garbageValue}, size)

    return buf
}

This function's behavior sends back a new byte slice filled with the garbage value allocated on Go's heap. We assume the garbage values are byte size. Lower than or equal to zero size will return nil, which may be handled differently from a NULL void pointer. Note in Go you don't usually worry about freeing the memory, the runtime takes care of this when there are no more references. 

Equivalents in Go for void pointers don't quite exist the same way they do in C. Slices are a general means for working with sequence of typed data. Smaller manipulations like direct memory modifications via memset depend on the implicit slice or string mechanisms.