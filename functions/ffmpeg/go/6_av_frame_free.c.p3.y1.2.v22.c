As Go language does not support pointer to pointer as C does and handles memory in its own manner, the semantics will not fit perfect fit, however here's a possible reproduction. The key difference is we can now have frame being set to nil from the outside of the function. Still, this type of translation the function leads to unsafe memory handling representaint antipattern of coding in Go.

go
import "github.com/giorgisio/goav/avcodec"

func avFrameFree(frame **avcodec.Frame) {
    if frame == nil || *frame == nil {
        return
    }
    avcodec.AvFrameUnref(*frame)
    *frame = nil
}
