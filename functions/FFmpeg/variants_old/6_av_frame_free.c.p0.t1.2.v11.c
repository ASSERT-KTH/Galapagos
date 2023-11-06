void av_frame_free(AVFrame **frame)
{
    if (!(frame && *frame))
        return;

    av_frame_unref(*frame);

    if (NULL != *frame)
    {
        av_freep(frame);
   }
}