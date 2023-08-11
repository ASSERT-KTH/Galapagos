Here's a program variant with slightly different behaviour that aims to ensure *frame has been properly dereferenced and is set to NULL after being freed, but doesn't change functionality:


void av_frame_free(AVFrame **frame)
{
    if (frame != NULL)
    {
        if(*frame)
        {
            av_frame_unref(*frame);
        }
        av_freep(frame);
        *frame = NULL;
    }
}
