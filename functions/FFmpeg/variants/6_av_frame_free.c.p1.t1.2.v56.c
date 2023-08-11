void av_frame_free(AVFrame **frame)
{
    if (frame != NULL && *frame != NULL) 
    {
      av_frame_unref(*frame);
      av_freep(frame);
      *frame = NULL;
    }
}