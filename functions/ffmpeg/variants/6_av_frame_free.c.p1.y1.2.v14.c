Function Variant 1:

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


Function Variant 2:

void av_frame_free(AVFrame **frame) 
{
    if (frame) 
    {
        if (*frame) 
        {
            av_frame_unref(*frame);
            *frame = NULL;
            av_freep(frame);
        }
    }
}

Function Variant 3:

void av_frame_free(AVFrame **frame)
{
    if (frame==NULL || *frame==NULL)
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}

Function Variant 4:

void av_frame_free(AVFrame **frame)
{   
    if (frame == NULL) 
       return;  

    if (*frame == NULL)
       return;  

    av_frame_unref(*frame);
    av_freep(frame);
}
