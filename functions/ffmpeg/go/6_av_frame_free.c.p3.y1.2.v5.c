In the Go language, functions related to external libraries require the cgo system so calling non-Go functions isn't directly applicable like in C. The "AVFrame" and "AVFrame_unref" functions aren't native Go objects so they can not be reproduced precisely in native Go language. However, an equivalent function skeleton can be nominated in Go using interfaces:

go
func avFrameFree(frame **interface{}) {
    if frame == nil || *frame == nil {
        return
    }

    // Specific av_frame_unref function don't have native Go equivalent, explicit conversion is needed 
    // avFrameUnref(*frame)

    *frame = nil
}

Please note that the semantics is kept same, though depending on the C library that provides AVFrame, obvious adaptions and optimizations should be done. For "av_freep" we are directly setting to `nil` because Go has its own garbage collection and assigning `nil` helps that process.