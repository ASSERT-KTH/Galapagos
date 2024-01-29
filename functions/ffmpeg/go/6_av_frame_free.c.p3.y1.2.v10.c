Unfortunately, there isn't a direct equivalent in Go for the C version as Go is garbage collected, it does not allow explicit memory deallocation/reallocation.

Also pointers in Go have a different role than in C. In Go, there are no pointer arithmetic and everything is done via slices and maps for dealing with arrays and dynamically growing arrays as opposed to C’s raw pointer based arrays.

C's libraries, data types, and functions vary greatly from Go's, meaning they can't be utilized in the same manner.

However, you can remove items from slice, which can partially simulate `free` procedure, like this:

go
func freeAVFrame(frames *[]AVFrame, index int) {
	// Remove frame at index and maintains the order of slice
	copy((*frames)[index:], (*frames)[index+1:])
	*frames = (*frames)[:len(*frames)-1]
}


In this example `AVFrame` would be a struct containing your VideoFrame info. The caller should provide the index at which the frame is located in slice. Mismatching type `AVFrame**` to simply `*[]*AVFrame` also reflects the difference between Go and C underlying types and the roles of pointers in both languages which cannot be directly translated.

Notice that Go automatically reclaims memory not used anymore by underlying mechanisms (garbage collector), so you would not need to worry about that.

Unless the functionality/constants of av_frame_unref and av_freep provided by the original C code is known, there is no counterpart implementation of such functions in Go as its behavior on multiple aspects isn't possible due to language specification (like deferencing, getting memory of allocation, direct deallocation).