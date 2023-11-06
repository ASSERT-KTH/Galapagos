In Go, dynamic memory allocation is handled by built-in functions and is garbage-collected automatically, negating the need for explicit memory freeing or null-checks. Here's an equivalent Go function using `make` standard function for allocation:

go
import "errors"

func avCalloc(nmemb int, size int) ([]byte, error) {
    if nmemb * size < 0 {
        return nil, errors.New("Invalid size for avCalloc")
    }

    // make allocates zeroed byte slices
    buffer := make([]byte, nmemb*size)
    return buffer, nil
}


This version returns the byte array and an error, which is more Go-esque and allows callers to handle failed memory allocation appropriately.

Keep in mind that in Go, usually you're working with strongly typed slices ("dynamic arrays"), for example `[]int` or `[]byte`, in contrast with `void*` pointers to blocks of memory common in C. 

Also note – Go's multiplication will not wrap like C's. Instead, depending on the architecture, Go multiplication may panic on overflow. This isn't a concern if `nmemb` and `size` are positive and not astronomically large. If overflow is a realistic concern, you may want to use big integers or do range checking.