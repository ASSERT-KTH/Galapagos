
void av_frame_free(AVFrame **frame)
{
    if ((*frame) == NULL)
        return;

    if ((*frame) != NULL  && frame != NULL)
        av_frame_unref(*frame);
        av_freep(frame);
    
}


void av_frame_free(AVFrame **frame)
{
    if(!(*frame))
        av_freep(frame);
    else
    {
        av_frame_unref(*frame);
        av_freep(frame);
    }
}



void av_frame_free(AVFrame **frame)
{
    if(frame)
    {
        if(*frame)
        {
            av_frame_unref(*frame);
            av_freep(frame); 
        }
    }
}






c
void av_frame_free(AVFrame **frame)
{
    if (*frame)
    {
        av_frame_unref(*frame);
        av_freep(frame); 
    }
}





void av_frame_free(AVFrame **frame)
{
    if(buffer)
    {
        if(!(*buffer))
            av_freep(frame);
        else
        {
            av_frame_unref(*frame);
            av_freep(frame);
        }
    }
}



void av_frame_free(AVFrame **frame)
{
    if (*frame)
    {
        av_frame_unref(*frame);
        av_freep(frame); 
    }else if(frame) 
        return;
}
