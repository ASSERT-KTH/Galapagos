The to-go C function is doing few things in an unconventional or strange way. Here's a simplified Go version:

go
import "unsafe"

func av_freep(arg unsafe.Pointer) {
    ptr := *(*unsafe.Pointer)(arg)

    *((*unsafe.Pointer)(arg)) = nil

    av_free(ptr)
}


The above code assumes that you have definition for `av_free()` function implemented same way as in C.

Kindly, do note:

1. Go doesn't have `memcpy()` function like C. But `unsafe.Pointer` helps here.

2. Go standard discourages the use of the `unsafe` package, and it's recommended to find a safe alternative while programming common project.

3. Go-enabled version of `av_freep()` function implemented above doesn't run automatically garbage collector (like C `free()` deallocate memory immediately). You have to run garbage collector manually if it is must, which happens due to difference between idiomatic code of C and Go.

Use this type of construct judiciously because it can make programs less portable, more difficult to understand, debug and maintain.