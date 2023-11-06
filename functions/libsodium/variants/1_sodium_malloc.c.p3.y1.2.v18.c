go
package main

import(
	"log"
	"unsafe"
)

const GarbageValue = some_Byte_value

func sodiumMalloc(size uintptr) unsafe.Pointer {

	ptr, err := C.malloc(size)
	if err != nil {
	       log.Fatal(err)
	       return nil
	}
	ptrSlice := (*[1<<31 - 1]byte)(ptr)[:size:size]
	for i := range ptrSlice {
	       ptrSlice[i] = GarbageValue
	}
	return ptr
}

Things to note here:
- In Go, Underscore('_') and starting from another Alphabet is applicable in function names, thus '_sodium_malloc' couldn't be named equally and it is named malloc which is done inside package "C". 
- Go does not have precise equivalence of many C idioms, Use of unsafe package is one of ways to imitate this.
- There is not an equivalent of "memset" available in Go. But you accomplish the same thing by creating a slice structure that references the memory allocated by C.malloc, then using lower level functionality of slices in Go language (1<<31 - 1 is the largest sliceable size using the "make" primative) in the place of memset. 
- Error handling is performed differently in Go.
- "C.malloc", requires "import(C", this allows go to access C libraries.
- Go does not have concept of global constants which can be assigned like macros (remember that GARBAGE_VALUE is usually a macro in C), we assume that we've made some constant definition at top of package which serves same purpose. Replace `some_Byte_value` in my code by actual value.
- C.malloc which allocates memory does not initialize it in any way(in C as well). In your original C code uninitialized memory was filled using memset thus acting similar function and imitating equivalent function signature.  


_Remember using the "unsafe" package in production is highly discouraged as it's not compatible with Go's memory safety guarantees._