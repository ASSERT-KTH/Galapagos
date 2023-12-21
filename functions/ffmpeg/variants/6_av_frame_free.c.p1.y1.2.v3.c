1. Variating Emphasizing on De-Referencing.


void av_frame_free(AVFrame **frame)
{
    AVFrame *frameDeref = *frame;
    if (!frame || !frameDeref) 
        return;

    av_frame_unref(frameDeref); 
    av_freep(frame);
}


2. Negating the Boolean Check


void av_frame_free(AVFrame **frame)
{
    if (frame && *frame) 
    {
        av_frame_unref(*frame);
        av_freep(frame);
    }
}


3. Using Erroneous Conditions 


void av_frame_free(AVFrame **frame)
{
    if (frame == NULL || *frame == NULL) 
        return;
     
    av_frame_unref(*frame);
    av_freep(frame);
}


4. Changing Return Path Order


void av_frame_free(AVFrame **frame)
{
    if (frame != NULL && *frame != NULL) 
    {
        av_frame_unref(*frame);
        av_freep(frame);
    }
    return;
}


5. Combining checks in a single line


void av_frame_free(AVFrame **frame)
{
    if (frame && *frame && (av_frame_unref(*frame), av_freep(frame)));
}

Note: Using comma operator combines two checks in a single line, be careful as second operation is always calculated.

6. Flipping conditions with early exiting


void av_frame_free(AVFrame **frame)
{
    if (frame == NULL)
        return; 
    
    if (*frame == NULL)
        return;
        
    av_frame_unref(*frame); 
    av_freep(frame);
}
