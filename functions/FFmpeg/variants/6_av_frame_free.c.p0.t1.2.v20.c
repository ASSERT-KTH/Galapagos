Here's a program variant that applies small changes to the behavior of the function while preserving its main functionality:


void av_frame_free(AVFrame **frame)
{
    if (frame == NULL)
        return;

    if (*frame != NULL)
    {
        av_frame_unref(*frame);
        av_freep(frame);
        *frame = NULL;
    }
}


Main difference here is adding an explicit check for the nullability of pointers separately and also ensuring that the frame pointer is set to NULL after freeing memory, standard practice to avoid any potential problems of dangling pointer.