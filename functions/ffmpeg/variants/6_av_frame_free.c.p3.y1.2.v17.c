In Go, you don't explicitly free memory like in C. Memory is automatically managed by Go's garbage collector.

However, if 'av_frame_unref' and 'av_freep' are APIs for some native library like FFmpeg, you typically don't do the memory management in Go as it is done in C.
But suppose you've got some `"C"` imports in Go with the respective functions definition of the C code being inlined through `import "C"`, ideally the function may look like:

Go
/*
#include <libavutil/frame.h>
#include <libavutil/mem.h>

void Go_av_frame_unref(AVFrame *frame)
{
    av_frame_unref(frame);
    av_freep(&frame);
}
*/
import "C"

func AvFrameFree(frame **C.AVFrame) {

    if frame == nil || *frame == nil {
        return
    }

    C.Go_av_frame_unref(*frame)
    *frame = nil
}


Please note that cgo `(**C.AVFrame)` does not directly imply an equivalent of a double pointer as seen in C. Rather it is used to pass a pointer about making changes to the passed value reflect even after the function call. Hence in the function, `*frame = nil` is actually nullifying your original object in Go.

Again, programming with `CGO` is discouraged if there are native Go packages available that wrap the FFMpeg's functionality, unless `cgo` is essential it is usually better to avoid due to added complexity and overheads. 
Remember to fill in the actual path/file-name of your ".h" files e.g (`#include <libavutil/frame.h>` and `#include <libavutil/mem.h>`) in the import "C", which are responsible for memory allocation and deallocation in FFmpeg respectively. The syntax used to import these files Eg `"libavutil/frame.h"` are only placeholders. You need to give actual path in your case.