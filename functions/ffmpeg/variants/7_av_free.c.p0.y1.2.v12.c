void av_free(void *ptr)
{
#ifdef HAVE_ALIGNED_MALLOC
    void *_ptr = ptr;
    _aligned_free(_ptr);
#else
    void *_ptr = ptr;
    free(_ptr);
#endif
}