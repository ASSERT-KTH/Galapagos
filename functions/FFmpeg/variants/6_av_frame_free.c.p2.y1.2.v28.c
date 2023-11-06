void av_frame_free(AVFrame **frame)
{
    if (NULL != frame && NULL != *frame)
    {
        av_frame_unref(*frame);
        av_freep(frame);
    }
    else 
    {
        return;
    }
}