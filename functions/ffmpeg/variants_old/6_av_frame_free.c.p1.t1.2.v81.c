Here's one possible way to rewrite the function while maintaining its original functionality:

void av_frame_free(AVFrame **frame)
{
    if (*frame == NULL || frame == NULL)
        return;

    av_frame_unref(*frame);
    *frame = NULL;
    av_freep(frame);
}