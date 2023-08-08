Here's a variant of the function that maintains its original functionality:


void av_frame_free(AVFrame **frame)
{
    if (frame == NULL)
        return;
    if(*frame == NULL)
        return;
    av_frame_unref(*frame);
    *frame = NULL;
}
