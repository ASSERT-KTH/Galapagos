Variant 1:

void av_frame_free(AVFrame **frame)
{
    if (frame && *frame)
    {
        av_frame_unref(*frame);
        av_freep(frame);
    }
}

Variant 2:

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

Variant 3:

void av_frame_free(AVFrame **frame)
{    
    if (NULL == frame || NULL == *frame) 
     return;

    av_frame_unref(*frame);
    av_freep(frame);
}

Variant 4:

void av_frame_free(AVFrame **frame)
{
    if (!(frame == NULL || *frame == NULL))  
    {
        av_frame_unref(*frame);
        av_freep(frame);
    }
}
