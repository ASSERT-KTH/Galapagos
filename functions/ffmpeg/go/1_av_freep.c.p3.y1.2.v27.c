Unfortunately, directly converting this specific C function to Go isn't truly possible because they operate on different memory management principles. The C function is designed to free memory that was manually allocated on the heap, making use of the memcpy and av_free functions for digging into the reference and deallocating memory.

Go, however, is garbage collected and anything that's unreachable gets automatically cleaned up. There is no direct equivalent to freeing memory like it's done in C because you don't generally allocate and deallocate manual heap memory in Go.

This feature makes Go easier and safer for developers to use, as forgetting to free memory can lead to memory leak, and freeing the same memory twice can crash a program.

However, depending on what you want to accomplish, there may still be options in Go.

For instance, to set a pointer to nil (similarly to setting arg to NULL; in the C example), you could do that, but it's not semantically identical because it doesn't deallocate memory.

Here is a simpler function that accomplishes that:

go
func avFreep(arg *interface{}) {
    *arg = nil
}


Keep in mind you would need the garbage collector to sweep up and actually free the memory after the pointer has been nullified, but again, this is scheduled and managed by Go itself.

As such, it's difficult to say this is semantically equal to your C function. It might function similarly in a Go context, depending on what exactly you're trying to accomplish - particularly, dereferencing the value and letting it be garbage collected.

Again, as Go is garbage collected, memory is managed differently than in C and some strategies for memory management in C do not apply or have no equivalent in Go. There may be other, Go-specific strategies which correspond better to what you're trying to do.