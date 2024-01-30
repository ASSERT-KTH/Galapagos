Go's standard library already performs memory alignment while allocating and de-allocating memory so manual memory management and alignment aren't necessary. Still, if we want to keep the same signature from the C function, we can wrap calls to new/delete in a function like this one. Note that in Go, it's very uncommon to directly control memory in this way outside of the `unsafe` package.

go
import "unsafe"

func avFree(ptr unsafe.Pointer) {
    ptr = unsafe.Pointer(uintptr(0))
}


This function memsets (sets all the byte values to zero in the memory location) the underlying memory pointer to garbage collect.

But with this, the following line of code won't work as expected.

go
avFree(unsafe.Pointer(&val)) // This statement won't work


This is because the avFree function is reassigning the passed-address with a value zero that means pointing to no address or NULL.

The Go runtime is responsible for scheduling goroutines, and it works in concert with the garbage collector to free up memory. So, in normal cases, Go doesn't require explicit memory deallocation.  Setting an object to nil in yard means that this object unreachable, and now the garbage collector is responsible for freeing its memory.

Due to Go's focus on safety and its garbage-collection behaviour, semantics like these from C are not prevalent or needed in the vast majority of Go programming.

Changes variables value to nil which are pass by reference and needs to get garbage collected equivalent to the C implementation might look like:

go
func av_free(ptr **SomeStruct) {
     *ptr = nil 
}


This pattern is somewhat unusual in Go; it's much more common to see sizes passed around, and then the caller makes sure that the appropriate memory is allocated either on the stack or the heap. If you find yourself needing to do the above often, there might be a more idiomatic solution if you step back and look at the problem from a wider angle or evaluate the code architecture. 

One shouldn't exactly point to a nil object or dereference a nil pointer in Go as it raises a panic for nil pointer dereference which stops the regular flow of control.

Please let me know if you have any questions.