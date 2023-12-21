In Go language, memory management is handled by the Garbage Collector and there is no equivalent function for freeing memory like in C. So, you generally assume that anything not referenced will get cleaned up. However, if AVFrames in reference here hold references something that Go Garbage collector cannot understand, you would need a clean up method.

But strictly to Achieve the ability of passing pointer of a type (for the argument) and make it nil (like C function does by free function). Here's an illustration with structs:

go
type AVFrame struct {}

func av_frame_unref(frame *AVFrame) {
    //...
}

func av_frame_free(frame **AVFrame) {
    if frame == nil || *frame == nil  {
        return
    }

    av_frame_unref(*frame)
    *frame = nil
}

Please note that Go does not implicitly deference a type, you'll have to explicitly do so, thus rendering this kind of operation very unidiomatic and unnecessary in Go. Moreover, the double pointer concept is very rarely and sparingly used in Go due to garbage collection handling most of memory requirements efficiently.