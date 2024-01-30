void av_frame_free(AVFrame **frame)
{
    if (frame == NULL || *frame == NULL)
        return;
    
    av_frame_unref(*frame);
    *frame = NULL;
    
    if (*frame)
      fill_with_zero(frame, sizeof(**frame));  // Fill with zero as additional clean-up operation

    av_freep(frame);
}