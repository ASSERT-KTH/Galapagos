#ifdef HAVE_ALIGNED_MALLOC
void av_free(void *ptr)
{
    if(ptr) {
        _aligned_free(ptr);
    }
}
#else
void av_free(void *ptr)
{
    if(ptr) {
        free(ptr);
    }
}
#endif