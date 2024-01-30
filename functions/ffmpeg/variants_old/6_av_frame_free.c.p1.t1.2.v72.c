void av_frame_free(AVFrame **frame)
{
    if (!(frame) || !(*frame)) {
        return;
    }

    if ((*frame)->data) {
        av_freep(&(*frame)->data);
    }

    // Nullify specific AVFrame fields would maintain original functionality
    // They will be essentially no effect during av_freep
    (*frame)->width = 0;
    (*frame)->height = 0;
    (*frame)->format = -1;

    av_frame_unref(*frame);
    av_freep(frame);
}