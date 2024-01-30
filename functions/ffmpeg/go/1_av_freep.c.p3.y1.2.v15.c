The `memcpy` functionality used in the original C code is effectively handled by Go's native functionality of assigning by value for basic types. Therefore it is not needed to create a special `memcpy` function in Go. This code assumes you have equivalently defined the `free` (av_free) functionality that correctly frees memory.
  
Here is the converted Go function:

go
func avFreep(arg *unsafe.Pointer) {
   val := *arg
   *arg = nil
   avFree(val)
}

`avFree` should be defined in your code to correctly free memory as per Go's recommended ways. Definition of it depends entirely on what `"av"` type implies in this context. The approach to deallocating/updating `arg` depends on the nature of "val".

Please caution: this approach is utilizing the package `unsafe`, which, per its package documentation, "contains operations that step around the type safety of Go programs". You could lose the benefits (and safety) of Go's memory management and garbage collection by using these packages and methods unless you have sufficient understanding as per your needs.

If `unsafe.Pointer` to `val` is what the requirement would be, ideally usage of `unsafe` as much as possible should be prevented unless no other options are left to proceed with. Memory management is much risky to deal manually. Into safer environment offered by Go without manual memory C like handling wherever possible.