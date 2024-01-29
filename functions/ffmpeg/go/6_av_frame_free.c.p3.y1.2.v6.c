In Go, dealing with memory and garbage collection is a more high level process than in C. There typically isn't a direct Free method that you would call on complex objects. Instead, you would make them eligible for garbage collection, by set it to `nil` or remove all references to the object. Further up to the AVFrame distro, there might be a Close or Unref function that needs to be called before an AVFrame object can be freed up which would be analogus to the `av_frame_unref` method in the original C code. However without exact Go SDK for AVFrame, alternative can be given which generally hints how freeing up resources is done in Go:

Go doesn't follow a pointer-pointer concept like in C, so a semantically equivalent version is not possible, this is only a way of controling memory in go.

go
// Assuming frame to be of type *AVFrame
func avFrameFree(frame *AVFrame) {
    if frame == nil {
       return
    }
    
    frame.avFrameUnref()
    frame = nil    // Making it eligible for garbage collection
}


Code snippet makes the frame eligible for garbage collection, of course, actual garbage collection is not guaranteed at the instant of the object is unreferenced and is taken over by Go runtime. Please note, this answers the case to create a semantically equivalent function, for exact pointer like operation as real go plugin for AVFrame, object can vary it shape and method signature so not specifically possible. One may need to refer proper Go AVFrame SDK documentation if available.