void av_frame_free(AVFrame **frame)
{
    if (frame == NULL)
    {
        return;
    }
    else
    {
        if (*frame == NULL)
        {
            return;
        }
    }

    av_frame_unref(*frame);
    *frame = NULL;
    av_freep(frame);
}