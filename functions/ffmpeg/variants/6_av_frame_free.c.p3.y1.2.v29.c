Go does not support pointer to point as they can lead to unpredictable behavior. However, you can encapsulate the data into struct types to achieve your new av_frame_free semantic. 

Here is a possible equivalent version in Go:
go
type AVFrame struct {
    frame *FrameData
}

func av_frame_free(frame **AVFrame) {
	if frame != nil && *frame != nil {
		av_frame_unref((*frame).frame)
		delete(frame)      
	}
}

func av_frame_unref(frame *FrameData) {
	// implement according to the logic in C code
}

func delete(frame **AVFrame) {
    *frame = nil
}


Remember to redefine your own `av_frame_unref` function because Go does not contain it. 
Keep in mind that automatic garbage collection behaves quite different in Go than it does in C.

Note: The behavior of programs using more levels of indirection may differ slightly from the behavior of similar C programs. This translation is mainly providing the approach bet device solution probably needs to add your systems-specific AVFrame structure in go as well.