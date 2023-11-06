The equivalent Go could be:


import "unsafe"

func avFreep(arg *unsafe.Pointer) {
    val := *arg
    *arg = nil
    avFree(val)
}


Please, replace "avFree" with actual 'C' function.

This assumes that you have a avFree defined somewhere else in your Go code that's equivalent to the av_free used in the C code. It should most likely take an unsafe.Pointer as argument and free the underlying memory. 

This isn't an exact translation, but quite close as Go has garbage collector and pointers in Go are safer and manipulate them is not idiomatic as compared in 'C'. So the idiomatic solution would be to replace usage of `unsafe.Pointer` with strong typed pointer, struct, for example, `*Item`, depends on what the original 'C' function `av_freep` deal with and its callers declaration. 

Go program is not usually interact with freeing memory as 'C' program does, because Go uses its own garbage collector to cleanup unused objects, not the programmer's manually calls. If the avFree was replicated in Go. You may not need a transliteration of `av_freep` from 'C' but typically rewrite or reimplement based on Go's usage manners. It's important to ensure that what 'C' memory management behaviors do, find out if any of the ‘Go’ methods that are equivalent. 

Note that unsafe pointer arithmetic can easily break the Go code - so please be very aware when using 
'unsafe' module.