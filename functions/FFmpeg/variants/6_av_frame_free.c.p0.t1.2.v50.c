void av_frame_free(AVFrame **frame)
{
    if (!frame)
        return;
    
    if(!*frame)
        return;

    av_frame_unref(*frame);
  
    av_freep(frame);
}