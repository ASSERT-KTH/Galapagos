import (
       "unsafe"
       "reflect"
       "errors"
)

// Assume GARBAGE_VALUE is constant and coherent with Go syntax
const GARBAGE_VALUE byte = // insert value here
const MAX_SIZE int = 1<<31 - 1

func sodium_malloc(size int) (unsafe.Pointer, error) {
   // Go does not use System's malloc directly, 
   // using := makes "size" dynamic allocable under heap which means equivalent to malloc
    if size > MAX_SIZE {
        return nil, errors.New("Out Of Memory") 
    }
    
    // slice bytearray creation to simulate malloc (size specific array allocation )         
    bytearray := make([]byte, size)
    
    // filling it with garbage value is a way of initializing
    for index := range bytearray {
       bytearray[index] = GARBAGE_VALUE
    }

   // get the bytearray's Header
    header := (*reflect.SliceHeader)(unsafe.Pointer(&bytearray))
    
    // return the bytearray's data pointer as an unsafe.Pointer
    return unsafe.Pointer(header.Data), nil 
}
Please note:
- Go doesn't use manual memory management and therefore lacks in a specific parallel to malloc or free you might find in C. Memory allocation in Go is managed by the garbage collector which works differently from malloc/free.
- While conversion of make/malloc and initialization is easy to procure in Go, memory deallocation in Go isn't similar to that of C.