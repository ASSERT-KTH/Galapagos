Note that Go does not have built-in direct equivalent to C's `malloc` function or equivalent byte-filling function like `memset`, so the initialization of the pieces of memory will be done differently. You should replace `yourDefaultByteValue` with whatever default byte value you'd like to initialize. Also note `GARBAGE_VALUE` from C code has been replaced with `yourDefaultByteValue`

go
import "unsafe"

func sodiumMalloc(size uintptr) unsafe.Pointer {
    ptr := C.malloc(size)
    if ptr == nil {
        return nil
    }
	
	builder := NewSliceHeader({Data: ptr, Len: int(size), Cap: int(size)})

	for i := 0; i < len(builder.b); i++ {
		builder.b[i] = yourDefaultByteValue
	}

    return ptr
}


This code creates a new instance of unsafe.Pointer using the import package `C.malloc`, then creates a byte slice in Go over the same piece of memory. The remainder of the function then proceeds the same way the original did. If C.malloc cannot allocate the memory, return nil. Remove the nil check if in your use case memory will always be successfully allocated.

If you are looking for zeroed memory, you could use `C.calloc` instead of `C.malloc`; in this case there would be no need for the loop to initializes values in the slice. 

Ensure that this code is being run with pure Go where you have your code which requires this  .

Replace '#!/bin/bash' and '$GOROOT' as your Project path with corresponding   values config  in bash command as follows:
  
bash
cgo -godefs defs.go > defs_<PLATFORM>.go

Replace `<PLATFORM>` by your deployment platform.

A disclosure is that you're working with something that isn't really business as usual when you're dealing with Go.

Note: This has lot of limitation, directly unsupported Cgo practices not recommended for productive use and is not working similarly like C but tries bring some work like C Malloc, Memory setters etc best reach for garbage collector from documentation :- `https://github.com/golang/go/wiki/cgo`