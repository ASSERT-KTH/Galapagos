void av_frame_free(AVFrame **frame)
{
    AVFrame *tmpFrame = NULL;  

    if (!frame)
        return;
        
    if(*frame)
    {
        tmpFrame = *frame;
        *frame = NULL;
    }
    
    if(tmpFrame)
    {
        av_frame_unref(tmpFrame);
        av_freep(&tmpFrame);
    }
}