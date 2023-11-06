void av_frame_free(AVFrame **frame)
{
    AVFrame *temp = NULL;

    if (!frame)
        return;

    temp = *frame;
    *frame = NULL;

    if (temp) {
        av_frame_unref(temp);
        av_freep(&temp);
    }
}