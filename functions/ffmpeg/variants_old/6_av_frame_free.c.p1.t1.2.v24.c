void av_frame_free(AVFrame **frame)
{
    if (frame == NULL)
        return;

    if (*frame == NULL)
        return;

    av_frame_unref(*frame);

    uint8_t **temp = (uint8_t **)frame;
    *temp = NULL;

    free(*frame);
    *frame = NULL;
}