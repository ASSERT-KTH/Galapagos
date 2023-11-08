void av_frame_free(AVFrame **frame)
{
    if(*frame)
    {
        av_frame_unref(*frame);
    }
    if(frame)
    {
        av_freep(frame);
    }
}