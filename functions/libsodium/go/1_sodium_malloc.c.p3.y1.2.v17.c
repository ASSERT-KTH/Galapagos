Equivalent function in Go programming language might be the following:

Go
import "bytes"

func sodiumMalloc(size int) []byte {
    ptr := make([]byte, size)
    if ptr == nil {
        return nil
    }
    bytes.Repeat(byte(GARBAGE_VALUE), size)
    return ptr
}


Some major points worth noting:
1. Go takes care of garbage values initialization, all values in GO are initialized by zero value. memory allocation is guaranteed not to fail, so no need to check for NULL (or in Go terms, nil). Therefore, the condition checking if the memory allocation was successful does not translate to Go.
2. The equivalent to `malloc() + memset()` in Go, could probably be `make() + bytes.Repeat()`.
4. In Go, we do not often use raw pointer, we use slice.
5. We can't apply general binary operations in Go to pointer values (hence to a slice). const int GARBAGE_VALUE doesn't appear in the Go version because you couldn't use it the same way.
6. The built-in `make(t Type, size IntegerType)` function is used to dynamically create variables, slices, maps or channels, and returns an initialized (but not necessarily zero valued) value of type T (not `*T` as in new). For the arrays make passes backing array. This explains the switch from the void pointer to a byte slice, which is used to manipulate raw bytes, similar to what malloc purposes.
  
Use these takeaways of how Go differs from C intelligently! (: