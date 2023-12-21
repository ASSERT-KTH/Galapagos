There is no direct equivalent in Go because memory management, such as allocation and deallocation of memory for certain data types, is handled automatically in Go and doesn't need to be manually controlled as opposed to languages like C. 

However, if you are wrapping the related deallocating operation involved with reading complex data types being read via `unsafe.Pointer`, which abstracts any data of memory, the point here would be using `C.free` distinctly under `import "C"`, that links with regard to CGo specification.

The corresponding implementation would probably be similar to the following:

Go
import "C"

//export av_free
func av_free(ptr unsafe.Pointer) {
	C.free(ptr)
}


In expression, `//export av_free` builds a bridge toward the C world, but involves CGo that disrupts Go environment performance due to garbage collector hindrance. 

On account of that, one wouldn't recommend using it (it must be avoided unless importing C-specific functionality indeed).

Kindly respect the Go idiomatic way. Input validation, error check handling or data interface acceptance - as well as garbage collector - were conceived specifically to enhance Go routine functionality to its full potential. 
As far as I know, people try their utmost to switch the logic from C-based conditions - like this your demonstration - to Go as straight as a die. 

Remember always: More abstract over hardware-close invariably ranges somewhere.