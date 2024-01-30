Here is an alternative function that frees up the av frame:


void av_frame_free(AVFrame **frame)
{
    if (frame && *frame)
    {
       av_frame_unref(*frame);
       av_freep(frame);
    }
}
