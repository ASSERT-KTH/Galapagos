Given the provided C code, the aim is to free memory being allocated for certain pointers. golang manages its memory with Garbage Collector, so we don't need to release memory as it's being taken care of by the golang itself.

In your design. Considerations, if you wants to nullify this pointer value, here's how you can do that.

go
func av_freep(arg *interface{}) {
    *arg = nil
}


As mentioned before, the GC (Garbage Collector) might not remove the memory of *arg immediately from heap after its set to nil. But, later in time, these objects is collected and cleaned because it's no more accessible or can't be roots tracing.

Remember, exact control over memory like this isn't possible in Go, due to language's design. If you find yourself trying to perfectly map each element of C (like `free()` and `malloc()`) in your golang re-implementation, you might need to reconsider the system architecture and usage of pointer or overall functionality.