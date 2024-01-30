Go does not have a directly equivalent function to C's av_free() as Go's memory management is garbage collected, and does not require the programmer to manually manage memory (unlike languages such as C).

As context, the av_free() function checks if the C compiler has _aligned_malloc (meaning if it can allocate aligned memory buffer), if so it uses the equivalent _aligned_free() to deallocate that memory or else it uses default free().

Since this concerning hardware-level optimization and memory management features used by C (that aren't equally relevant or available in Go), this implementation is intrinsically non-portable. Go's memory deallocation is managed completely by its garbage collector rather than by the programmer.

So, this av_free function written in Go does essentially nothing.

go
package main

func av_free(ptr *interface{}) {
    // Do nothing.
}

However, this function can be tweaked to set argument (pointer) to nil triggering garbage collector by default. This assumes ptr to be a pointer held elsewhere that you would want to trigger for garbage collection from within this function.

go
package main

func av_free(ptr **interface{}) {
   *ptr = nil
}
