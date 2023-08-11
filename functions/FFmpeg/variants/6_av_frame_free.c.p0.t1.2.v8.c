void av_frame_free(AVFrame **frame)
{
    if (frame == nullptr || *frame == nullptr)
        return;

    if (av_frame_unref(*frame) != 0)
        return;

    if(av_freep(frame) != 0)
        return;
}