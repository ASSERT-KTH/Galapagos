In Go, we don't have pointers to pointers as it is idiomatic in C. We usually just pass pointers, or pass things by value and the garbage collector takes care of freeing the memory. Go doesn't have exact equivalents for 'av_frame_unref' and 'av_freep' as this looks like leveraging a specific C library. Nevertheless, if AVFrame has a method to handle it, the idiomatic equivalent in Go might be something like the following:

Go
func FreeFrame(frame *AVFrame) {
    if frame == nil {
        return
    }

    frame.Unref()
    frame = nil
}


Note that the 'frame = nil' sets the function's local copy of the pointer to 'AVFrame' to nil, rather than manipulating the passed value itself. There is no direct equivalent to "av_freep" in Go because all memory management it's all handled by garbage collection.

Besides, if 'av_freep' is doing something specific within your application then you may need to execute something more relevant within this function.

The nil assignment is more for semantical completion, as Go's GC deallocates stuff off the heap when it sees nothing is referencing it. Given 'frame.Unref()', there shouldn't be anything referencing our data so making sure in deallocation is relatively superfluous, but good practice if we have any cleanup within 'Unref()' itself. 

Key takeaway is don’t try to do C-style coding in Go, as that Would not result in idiomatic, or even sensible, Go code.