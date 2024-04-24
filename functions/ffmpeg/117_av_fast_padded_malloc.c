void av_fast_padded_malloc(void *ptr, unsigned int *size, size_t min_size)
{
    uint8_t **p = ptr;
    if (min_size > SIZE_MAX - AV_INPUT_BUFFER_PADDING_SIZE) {
        av_freep(p);
        *size = 0;
        return;
    }
    av_fast_mallocz(p, size, min_size + AV_INPUT_BUFFER_PADDING_SIZE);
    if (*p)
        memset(*p + min_size, 0, AV_INPUT_BUFFER_PADDING_SIZE);
}