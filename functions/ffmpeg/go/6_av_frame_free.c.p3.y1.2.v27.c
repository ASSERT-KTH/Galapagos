Due to the fundamental differences between C and Go programming languages, a direct conversion isn't possible while maintaining the original function's "signature". Go does not support pointer to pointer parameters and also it has a garbage collector hence doesn't need, nor provides direct APIs to manage memory as you could do in C/C++ using functions like `free()`. Furthermore, the code uses specific methods like `av_frame_unref` and `av_freep`, these are implementation specific and do not exist standalone in Go.

However, here's an attempt to the objective of the function in Go programming language assuming you have accordingly defined the types and supporting dependent functions inside your Go code.

go
func frameFree(frame **AVFrame) {
    if frame == nil || *frame == nil {
        return
    }

    frameUnref(*frame)
    
    *frame = nil
}


The main concept shown in this code snippet is that you should basically "unset" or set to `nil` the existing value, rather than trying to "release" the memory directly. The Go garbage collector will automatically reclaim the unused memory, so this is typically the correct way to "free" resources in Go.

This implementation presumes that `AVFrame` is a type you've defined in your code and `frameUnref` is a function you have created that serves to clean up or unreference the `frame`, because these are not features built into the Go language.

Remember to adapt the code according to your full project because Go is managed compared to C which is unmanaged, thus difference and strategies about memory allocation and deallocation exist.