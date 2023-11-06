void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    if(ptr!=NULL) {
      _aligned_free(ptr);
      ptr = NULL; //setting pointer to NULL after free
    }
#else
    if(ptr!=NULL) {
      free(ptr);
      ptr = NULL; //setting pointer to NULL after free
    }
#endif
}