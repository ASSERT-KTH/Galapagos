In Go, parameters are passed by value so we can't directly implement the function 'av_frame_free' as in C which changes the source pointer to null. But if AVFrame struct had a method 'Free' if would look something like this:

Go
func (avFrame *AVFrame) Free(){
  if avFrame == nil {
    return
  }

  avFrame.unref()
  avFrame = nil
}


However please note that avFrame value won't be modified on your calling code if it's not a pointer to pointer (like in the C version "**Frame"). Also, we are considering that the "av_frame_unref" C function is equivalent to some "unref" method in Go version and "av_freep" is just setting the pointer to nil, hence the avFrame = nil line.