void av_frame_free(AVFrame **frame)
{
    if (frame == nullptr || *frame == nullptr)
        return;

    av_frame_unref(*frame);
    (*frame)->data[0] = NULL;
    av_freep(frame);
}