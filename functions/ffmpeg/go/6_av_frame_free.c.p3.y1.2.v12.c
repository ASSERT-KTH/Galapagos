Go does not support free memory directly like C, because it has a garbage collector that takes care of it. Instead, you just have to get rid of references to the variable to be garbage collected. A direct conversion from this C function to a Go function is not possible. 

To properly make a semantics equivalent, it would depend your abstract type from AVFrame and its methods such as av_frame_unref but normally Go would manage this internally with its garbage collector so we don't have a particular case as this one unless you are doing manually some unsafe-pointer management.
  
Also note that Golang does not support pointer to pointers (i.e `**frame` in C). Here is a basic work around.
go
type AVFrame struct {
    // attributes
}

func av_frame_unref(*frame *AVFrame) {
	// Clearing/nilling memory or internal stuff for unreference
}

func (fn *avFrame) Free() {
	if fn==nil || *fn==nil {
		return
	}

	av_frame_unref(fn)
	*fn = nil
}
