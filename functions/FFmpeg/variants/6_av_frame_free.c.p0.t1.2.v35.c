void av_frame_free(AVFrame **frame)
{
    if (frame == NULL)
    {
        return;
    }
    else if (*frame == NULL)
    {
        return;
    }

    av_frame_unref(*frame);
    av_freep(frame);
}