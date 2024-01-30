void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    if (ptr != NULL) {
      _aligned_free(ptr);
      ptr = NULL;  // added functionality go set null after free
    }
#else
    if (ptr != NULL) {
     free(ptr);
     ptr = NULL;  // added functionality to set null after free
    }
#endif
}