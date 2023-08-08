void av_freep(void **ptr)
{
    if (ptr)
    {
        av_free(*ptr);
        *ptr = NULL;
    }
}