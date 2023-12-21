In Go, you can't exactly mimic the behaviour of the C code snippet because of language differences. Go uses a Garbage Collector and doesn't require to free up memory manually. 

However, assuming the 'av_frame_unref' behaved as setting the frame object to its zero value, this might be the closest equivalent.

go
func avFrameFree(frame **AVFrame) {
    if frame == nil || *frame == nil {
        return
    }

    *frame = nil
}


As for `av_freep(frame);`, it's probably safe to call some close or cleanup method if exists in your code, else directly invoking garbage collector could be disastrous for your Go application. 

Again important to know! unlike in `C` where you might need to manage your own memor, Go relies on the automatic garbage collection.