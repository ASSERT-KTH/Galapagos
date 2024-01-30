In Go, it's complicated to exactly mimic the behaviour of this C function because allocation and multiplication are both potentially hazardous operations that have their errors handled separately, even more to the point, explicit error handling is important.

However, a basic version similar to the C function with appropriate edits can be provided:

go
import "unsafe"

func avCalloc(nmemb, size uintptr) unsafe.Pointer {
    result := nmemb * size
    return calloc(result)
}


This function would be paired with another calloc function that effectively zeroes memory (which av_mallocz does in the original C function).

It's NB to remember that `unsafe.Pointer` stands as a crude equivalent to void pointers in C.

NB Secondly, the complexity of error control needed for this kind of functions includes the inability of Go to panic during low-level memory issues or multiplication overflows - make sure to handle these carefully. 

NB Thirdly, The av_mallocz & size_mult types of C are specially used for memory allocation & for their behaviour during failures - this necessitates a custom way to detecting overflows.