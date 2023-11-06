1. Change order of conditions

void av_frame_free(AVFrame **frame)
{
    if (!*frame || !frame)
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}


2. If-expressions

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


3. Negative condition checking

void av_frame_free(AVFrame **frame)
{
    if (frame && *frame)
    {
        av_frame_unref(*frame);
        av_freep(frame);
    }
}


4. Enclosing block 

void av_frame_free(AVFrame **frame)
{
    if (!frame || !*frame) 
    {
        ;
    }
    else
    {
        av_frame_unref(*frame);
        av_freep(frame);
    }
}


5. Ternary operator

void av_frame_free(AVFrame **frame)
{
    (!frame || !*frame) ? : (av_frame_unref(*frame), av_freep(frame));
}
