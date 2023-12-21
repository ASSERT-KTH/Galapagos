Variation 1:


void av_frame_free(AVFrame **frame)
{
    if (frame != NULL && *frame != NULL)
    {
        av_frame_unref(*frame);
        av_freep(frame);
    }
}

Variation 2:


void av_frame_free(AVFrame **frame)
{
    if (frame && *frame) 
    {
        av_frame_unref(*frame);
        av_freep(frame);
    }
}


Variation 3:


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


Variation 4:


void av_frame_free(AVFrame **frame)
{
    if (!(!frame || !*frame))
    {
        av_frame_unref(*frame);
        av_freep(frame);
    }
}


Variation 5:


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
