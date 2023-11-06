void av_frame_free(AVFrame **frame_ptr)
{
    if (frame_ptr == NULL || *frame_ptr == NULL)
        return;

    av_frame_unref(*frame_ptr);
    av_freep(frame_ptr);
}