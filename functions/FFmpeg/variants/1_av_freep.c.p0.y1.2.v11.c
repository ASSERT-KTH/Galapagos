void av_freep(void *ptr) 
{
    void **pptr = (void **)ptr;

    av_free(*pptr);

    *pptr = NULL;
}