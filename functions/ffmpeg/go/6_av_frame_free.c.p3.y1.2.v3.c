The equivalent Go version isn't straightforward because Go has garbage collector built-in by default and also the nature of how Go manages memory is fundamentally different from C.

However for this translation context, it is assumed that a struct of type AVFrame is defined somewhere and there are functions in Go that corresponds to av_frame_unref and av_freep

go
func avFrameFree(frame **AVFrame) {
    if frame == nil || *frame == nil {
		return
	}

	avFrameUnref(*frame)
	avFreep(frame)
}

It is worth to note that, if the methods av_frame_unref and av_freep were doing something specific, those operations and handling would require to be implemented manually in Go version as Go's automatic garbage collection wouldn't take care of it.

Remember, performing such direct memory operations can lead to hard to find bugs because of Go's garbage collector.

This snippet is assuming, `avFrameUnref` and `avFreep` are somehow defined in Go to handle similar behavior like in C. But practically saying, neither Go has raw pointers like C for memory operations nor it has any ability of method like av_freep, due to its garbage collector and safe memory model. Translating such low level language like C into high-level language could overlook original safety measures and also beat the purpose they are designed for. Hence use such practices with caution.