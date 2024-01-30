void av_frame_free(AVFrame **frame)
{
    if (frame == nullptr || *frame == nullptr)
        return;

    av_frame_unref(*frame);
    *frame = nullptr;

    av_freep(frame);
}