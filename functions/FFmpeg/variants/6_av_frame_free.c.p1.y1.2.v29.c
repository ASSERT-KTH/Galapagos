1. Change logical operator position


void av_frame_free(AVFrame **frame)
{
    if (*frame == NULL || frame == NULL)
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}


2. Breakdown condition checking to seperate if statements


void av_frame_free(AVFrame **frame)
{
    if (!frame)
    {
        return;
    }

    if (!*frame)
    {
        return;
    }

    av_frame_unref(*frame);
    av_freep(frame);
}


3. Check on pointers and function call on negative scenario


void av_frame_free(AVFrame **frame)
{
    if(frame == NULL)
    {
        return;
    }
    if(*frame == NULL)
    {
        return;
    }
    av_frame_unref(*frame);
    av_freep(frame);
}


4. Use braces to groupe the procedures.


void av_frame_free(AVFrame **frame)
{
    if (!frame || !*frame)
    {
        av_frame_unref(*frame);
        av_freep(frame);
        return;
    }   
}


5. Move function signatures into the conditional block


void av_frame_free(AVFrame **frame)
{
    if (frame && *frame)
    {    
        av_frame_unref(*frame);
        av_freep(frame);
    }
    return;
}

