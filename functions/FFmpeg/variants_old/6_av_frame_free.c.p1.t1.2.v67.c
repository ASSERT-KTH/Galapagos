void av_frame_free(AVFrame **frame)
{
   /* Check if the pointer to AVFrame pointer is NULL */
    if(!frame)
        return;

    /* Check if the content of the AVFrame pointer is NULL */
    if(*frame != NULL)
    {
        /* If it's not NULL, then unload the frame first */
        av_frame_unref(*frame);

        /* Then free/release the frame memory */
        av_freep(frame);
    }
}