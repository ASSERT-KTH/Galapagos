The C function `av_freep` deallocates memory referred by `arg` and then sets it to NULL.

Regarding the given challenge, the task of manual memory management which includes explicitly freeing up memory, is not available in higher-level languages such as Go. Go has automatic garbage collection which removes the need for manual memory deallocation.

Thus, this means that the function doesn't have a direct equivalent in Go. Nevertheless, if required, a possible Go translation can be:

go
func av_freep(arg *interface{}) {
    *arg = nil
}


However, it's important to mention that although this function sets the provided pointer to `nil`, it doesn't ensure deallocation of memory. Though this will enable garbage collection for `arg` if it contains the only reference to particular object in memory, it is not equivalent to the `av_free` function's capability of freeing up memory space explicitly.