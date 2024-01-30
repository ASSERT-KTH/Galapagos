Option 1:

void av_frame_free(AVFrame **frame)
{
    if (frame != NULL )
    {
        if(*frame != NULL) 
        {
            av_frame_unref(*frame);
            av_freep(frame);
        }
    }
}

Option 2:

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

Option 3:

void av_frame_free(AVFrame **frame)
{
    if( frame && *frame)
    {
        av_frame_unref(*frame);
        av_freep(frame);
    }
}

Option 4:

void av_frame_free(AVFrame **frame)
{
    if(!frame) 
    {
        return;
    }

    if(!*frame)
    {
        return;
    }

    av_frame_unref(*frame);
    av_freep(frame);
}

Option 5:

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
