void av_frame_free(AVFrame **frame)
{
    if (frame == NULL || *frame == NULL) return;

    av_frame_unref(*frame);
    
    if (*frame && (*frame)->extended_data == (*frame)->data)
        (*frame)->extended_data = NULL;

    av_freep(frame);
}