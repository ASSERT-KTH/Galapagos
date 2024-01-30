In Go, we never use `free` function like we do in C or most of the other low level languages. Memory is controlled by the Go garbage collector.. Although Go does not have exact equivalents to freeing the memory manually; note that Go is a garbage-collected language and manual memory management is not directly applicable.

But you can kind of mimic the freeing of memory through setting the pointers to `nil` - effectively clearing references so that Garbage Collector(GC) may do its job at some point handled primarily by the runtime.

First we need sort of a mock `AVFrame`s struct and `av_frame_unref` function to give a more complete code(invisible part below);

Will fill this references to give a complete visible semantic equivalent;

type AVFrame struct {
    /* some fields */
}

func av_frame_unref(frame *AVFrame) {
    /* frame unreference function logic here. */
}


As in the original cited c codepart,

func avFrameFree(frame **AVFrame) {
    if frame == nil || *frame == nil {
        return
    }
    av_frame_unref(*frame)
    *frame = nil
}

The manual dereferencing of object pointers, creating an extra pointer `**AVFrame` then `*frame = nil` which imitates direct memory management in C-style isn't common; more tightly,

func avFrameFree(frame *AVFrame) {
    if frame == nil {
        return
    }
    av_frame_unref(frame)
}

is favored most probably. Naturally, lots of third party libraries would need ffi libraries to handle calls like freeing structures referenced by the pointer. After we're done with freeing C-Go obj. within the code wrapping utilizing finalizer . We can otherwise wrap a reference-counted schema for AVFrames on top of this finalizer.

Being said warning also applies due must please note that Go is a garbage collected language - features like auto (heap store, non-stack) sent objects memory cleanup which retain early referenced pointers is literally more preferred - no unresolvable pointer, conflicting branches etc will exist crossing program lines, encouragingly with Clean Syntax + the Robustness aforementioned reasoning. The directly analogous version is not necesary for the corrected illustration and GC'ed environment - truly this keeps space fast dealloc and efficient in GoLang so objects and res. likewise might deconstructed when and if nearer pointer value addresses haven't touched(track) for a while(more on algos. lv.).  Even purely based on this, observer might needn't to replace existing logic filling addresses instead decrease objs(unreferenced ones only collection).
Methods provide for built not implementation filtered thus preserving actual representation and the upcoming patches more, however always with great reserved understanding aspect.