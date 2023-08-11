void av_frame_free(AVFrame **frame)
{
    if (frame != NULL && *frame != NULL) {
        if ((*frame)->data[0] != NULL) {
            av_frame_unref(*frame);
        }
        av_freep(frame);
    }
}