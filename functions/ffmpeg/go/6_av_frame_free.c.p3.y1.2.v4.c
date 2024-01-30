In the Go programming language, the translation of this code will heavily depend on the ways `AVFrame`, `av_frame_unref`, and `av_freep` are implemented. Unfortunately, Go does not support pointer to a pointer (**), as you used to free up memory in C. Also, since Go is a garbage collected language, memory management is largely in the hands of its runtime, therefore memory releasing functions like `av_freep` can't be represented in Go at semantic equivalent. 

Nevertheless, making some strong assumptions that AVFrame and its pointer counterpart are used in Go and there's method on that structure named Unref slightly similar to av_frame_unref, a version of the function could be:

 go 
func av_frame_free(frame **AVFrame) {
	if frame == nil || *frame == nil {
		return
	}

	(*frame).Unref()
	// The following line is extraneous, Go garbage collector takes care of this:
  *frame = nil
}


Reminder: Go manage the memory allocation and deallocation for us and `AVFrame` type on which your are relying should itself be responsible for freeing any associated memory before it becomes unreachable from the Go runtime. That's why Av_freep() equivalent statement is not needed in Go.  
Because of the fundamental difference between C and Go about memory management, the full translation of such a function, with all of its details, might not be achieved in Go.