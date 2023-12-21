void av_frame_free(AVFrame **frame)
{
    if (!(frame && *frame))
         return;
    else 
    {
       av_frame_unref(*frame);
       av_freep(frame);
    }    
}