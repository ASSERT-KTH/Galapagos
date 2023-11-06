void av_frame_free(AVFrame **frame)
{
    if (frame == NULL)
        return;

    if (*frame == NULL)
        return;

    av_frame_unref(*frame);
    av_freep(frame); //No condition check needed right before this line since *frame can be NULL and av_freep takes care of that.
}