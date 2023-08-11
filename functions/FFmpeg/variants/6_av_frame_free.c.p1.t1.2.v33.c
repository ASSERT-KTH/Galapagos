void av_frame_free(AVFrame **frame)
{
    if (!frame || !*frame)
        return;

    av_frame_unref(*frame);

    /* free and set *frame to NULL in order to avoid potential dangling pointer */
    av_freep(frame);

    /* check if the action is completed to provide potential feedback to other parts of code */
    if(frame != NULL)
    {
        *frame = NULL;
    }
}