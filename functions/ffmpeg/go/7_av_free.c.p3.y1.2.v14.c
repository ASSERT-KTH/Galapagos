Go doesn't support preprocessor directives like `#if` and `#endif`. Also, all allocations in Go are 8-byte aligned and there's no separate function to free aligned memory. Furthermore, go take cares of garbage collection for unused variables automatically, without using a free() function like in C. 

So the given code does not make sense in Go given these considerations and differences from C. But for the purpose of exercise and following the context of question, in Go memory can be freed by setting pointer to nil. Below is the partial equivalent in Go which assumes obj *T initialised properly: 

go
func avFree(obj *T) {
    obj = nil
    runtime.GC()
}


Calling runtime.GC() is not actually necessary but just highlights the fact that the garbage collector can and may run after this we set the obj to nil. Usually, you shouldn't use runtime.GC() because Go's garbage collector is very efficient in cleaning up unused memory on its own.

Remember that using this technique doesn't exactly replicate `free()` from C as memory management in Go is automatically performed by garbage collector. We cannot force an object to be "freed" instantly like in C. The garbage collector will do it automatically when the memory is no longer referenced and if it determines it's a good time to do the cleanup (based on memory pressure and other factors).