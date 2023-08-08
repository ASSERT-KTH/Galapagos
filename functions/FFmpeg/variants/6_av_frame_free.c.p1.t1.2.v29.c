void av_frame_free(AVFrame **frame)
{
    if (!frame)
        return;

    if (*frame) {
        av_frame_unref(*frame);
        *frame = NULL;
    }
    
    av_freep(frame);
}