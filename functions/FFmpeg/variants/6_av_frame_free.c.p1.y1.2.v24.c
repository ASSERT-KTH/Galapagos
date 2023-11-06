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
    if (frame == NULL || *frame == NULL)
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}


Variant 4:

void av_frame_free(AVFrame **frame)
{
    if (!(!frame || !*frame))
    {
        av_frame_unref(*frame);
        av_freep(frame);
    }
}


Note: When you are to support other transformation requests please refer to your specific coding standard and conventions in mind.