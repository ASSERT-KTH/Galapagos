void av_frame_free(AVFrame **frame)
{
    if (frame != NULL) 
    {
        if (*frame != NULL)
        {
            av_frame_unref(*frame);
            av_freep(frame);
        }
    }
}