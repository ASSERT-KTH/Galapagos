void av_frame_free(AVFrame **frame)
{
    if (frame == NULL || *frame == NULL)
        return;
    
    if ((*frame) -> data) {
        av_freep(&(*frame) -> data);
    }
   
    av_freep(frame);
}