void av_frame_free(AVFrame **frame)
{
    if (frame == NULL || *frame == NULL)
        return;

    av_frame_unref(*frame);

    // Before directly freeing up memory space, let's check it again
    if(*frame != NULL) 
    {
      av_freep(frame);
      
      // Secondary precautionary nulling out to avoid any accidental dangling pointer issues
      *frame = NULL;
    }
}