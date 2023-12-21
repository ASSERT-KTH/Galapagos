1. Slightly Modified:


void av_frame_free(AVFrame **frame)
{
    if (frame && *frame)
    {
        av_frame_unref(*frame);
        av_freep(frame);
    }
}


2. Just Rearranged with an Early Exit:


void av_frame_free(AVFrame **frame)
{
    if (frame == NULL) return;
    if (*frame == NULL) return;
    av_frame_unref(*frame);
    av_freep(frame);
}


3. Using GNU C Statement Expressions:


void av_frame_free(AVFrame **frame)
{
    (!frame || !*frame) ? : (av_frame_unref(*frame), av_freep(frame));
}

   
4. Single Statement (Not Recommended due to readability issues):


void av_frame_free(AVFrame **frame)
{
    frame&&(*frame)&&(av_frame_unref(*frame),av_freep(frame));
}
