Please note that due to the differences between C and Go, it's not entirely possible to maintain the original function's signature exactly because Go is statically typed and treats null values differently than C. This might not exactly be an in-place replacement for `av_freep()` in Go, but here is a version that in Go that exhibits similar behavior:

go
func avFreep(arg *interface{}) {
	val := *arg
	*arg = nil
	avFree(val)
}


You need to implement your `avFree()` function as, Go language does not have `free` operation to explicitly release memory back to the computer. 

Please assume a function called avFree() exists outside of this example which destroys/removes the value you give it so you don't risk memory losses. Otherwise remove that line of code, because Go's garbage collector should automatically de-allocate memory to a pointer that does not have any reference.

Moreover, as `void pointers` from C don't necessarily have a direct equivalent in Go, we can use `interface{}` for the purpose which can hold values of any type. The argument `arg` is a pointer to an `interface{}`. We're assuming `av_free()` is analogous to deallocating or making the object unusable in some manner (we cannot directly free memory like in C due to Go's garbage collector).