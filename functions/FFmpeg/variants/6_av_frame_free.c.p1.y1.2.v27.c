1. Reordering Conditions

void av_frame_free(AVFrame **frame)
{
    if (!*frame || !frame)
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}

2. Separately Testing Each Condition

void av_frame_free(AVFrame **frame)
{
    if (!frame)
        return;
        
    if (!*frame)
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}

3. Merge both lines into one line

void av_frame_free(AVFrame **frame)
{
    if (!frame || !*frame) return;
    av_frame_unref(*frame);
    av_freep(frame);
}

4. Using != instead of ! 
 
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

5. Nested If blocks 
 
void av_frame_free(AVFrame **frame) 
{ 
    if (frame != NULL)
    {
        if(*frame != NULL)
        {
            av_frame_unref(*frame);
            av_freep(frame);
        }
    }
    return;
}
