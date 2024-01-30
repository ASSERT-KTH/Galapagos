In Go language, memory allocations are automatically handled by the garbage collector. Unlike C, Go doesn't provide the function to manually release the memory. Therefore, producing a semantically equivalent version of functions like `av_free(void *ptr)` - which release the memory manually - is not possible in Go.

However, setting the pointer value to `nil` in the Go language makes the given variable eligible for garbage collection.

Instead, here's a Go-language specific function after porting which doesn't directly perform memory deallocation but marks a comparable action:

go
type T struct { val []byte }

func (t *T) av_free() {
    t.val = nil
}

For any value type of `T`, this function would set the value（`val[]byte`）held by it to `nil`, thus adjusting this value to be discarded and garbage collected. After the disposal, it would not point to any memory location taken by the previously referred value.

Kindly note that deallocating memory in Go is handled automatically by Go's garbage collector, and one cannot directly invoke memory deallocation compared with C. Also, `_aligned_free()` has no direct equivalent in Go either, as the Go runtime handles all memory allocations and deallocations for a programmer.
**Memory management in Go is a tad dissimilar from languages such as C or C++. The garbage collector in Go will handle freeing up memory (like free function in C) on unused or unreachable variables or slices automatically. This keeps the code cleaner and simpler.