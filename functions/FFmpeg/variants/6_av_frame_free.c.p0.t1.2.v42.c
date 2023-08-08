void av_frame_free(AVFrame **frame)
{
    if (frame != nullptr && *frame != nullptr)
    {
        av_frame_unref(*frame);
        av_freep(frame);
        return;
    }
    return;
}