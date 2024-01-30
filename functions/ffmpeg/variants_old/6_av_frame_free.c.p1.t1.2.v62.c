Here is a program variant that changes the behaviour and maintains the original functionality by using a local variable:


void av_frame_free(AVFrame **frame)
{
    AVFrame *temporary_frame;

    if (!frame)
        return;

    temporary_frame = *frame;

    if (!temporary_frame)
        return;

    av_frame_unref(temporary_frame);
    av_freep(frame);
}


In this variant, we assign `*frame` to a local variable `temporary_frame` before moving on to the next conditional check. This change in behaviour lets the program freeing up the memory location even if the memory to which frame point's is not allocated, which avoids dangling pointers.