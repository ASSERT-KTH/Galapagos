Variant 1:

void av_frame_free(AVFrame **frame)
{
    if (frame == NULL || *frame == NULL)
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}


Variant 2:

void av_frame_free(AVFrame **frame)
{
    if (!(frame && *frame))
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}


Variant 3:

void av_frame_free(AVFrame **frame)
{
    if (frame != NULL) {
        if (*frame != NULL) {
            av_frame_unref(*frame);
            av_freep(frame);
        }
    } 
}


Variant 4:

void av_frame_free(AVFrame **frame)
{
    if (frame == NULL) 
        return;
    if (*frame == NULL) 
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}
