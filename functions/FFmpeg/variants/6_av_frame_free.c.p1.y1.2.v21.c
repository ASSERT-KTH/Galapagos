Variant 1:

void av_frame_free(AVFrame **frame)
{
    if (!(*frame == 0 || frame == 0))
    {
        av_frame_unref(*frame);
        av_freep(frame);
    }
}

Variant 2:

void av_frame_free(AVFrame **frame)
{
    if (frame) 
    {
        if (*frame)
        {
            av_frame_unref(*frame);
            av_freep(frame);
        }
    }
}

Variant 3:

void av_frame_free(AVFrame **frame)
{
    if (frame != 0 && *frame != 0)
    {
        av_frame_unref(*frame);
        av_freep(frame);
    }
}

Variant 4:

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
