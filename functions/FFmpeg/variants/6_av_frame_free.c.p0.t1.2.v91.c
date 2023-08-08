void av_frame_free(AVFrame **frame)
{
    if (frame == NULL)
        return;

    if(*frame == NULL)
        return;

    av_frame_unref(*frame);

    void **cast_to_generic_ptr = (void**)frame;
    av_freep(cast_to_generic_ptr);
}