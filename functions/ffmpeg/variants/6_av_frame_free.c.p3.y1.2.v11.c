In Go, connections or structures are often cleaned up with a method that corresponds to the structure, since there are no pointers to structs such as in C. In addition, Go has a garbage collector so you don't have to worry about freeing the memory as you clean up resources. Without seeing the full workings and dependencies of `av_frame_free`, an exact equivalent may violate these patterns commonly present in Go and its libraries.

With this in mind, a semantically similar function considering how Go does memory handling would be:

go
import "github.com/giorgisio/goav/avutil"

func AvFrameFree(frame **avutil.Frame) {
	if frame == nil || *frame == nil {
		return 
	}
	
	(*frame).AvFrameUnref()
	*frame = nil // Setting nil to clean up memory, specific "av_freep()" equivalent may depend on the library
}


Please make sure av_frame_unref(), and av_freep() in the provided Go library, carry out similarly to what they do in C code. This library(`"github.com/giorgisio/goav/avutil"`) might differ while offering ffmpeg functionalities, please check. Directions and details may vary in the library you are using. 

It should restated that manipulating pointers to pointers is generally obviated with Go's garbage collection, slice semantics, and resource cleanup practices. Please consider refractoring for better Go code unless there's a specific reason it should be like this.