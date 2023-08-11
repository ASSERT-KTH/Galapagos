#define SHIFT 0x10

void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    char *shifted_ptr = (char*)ptr - SHIFT;
    _aligned_free(shifted_ptr);
#else
    char *shifted_ptr = (char*)ptr - SHIFT;
    free(shifted_ptr);
#endif
}