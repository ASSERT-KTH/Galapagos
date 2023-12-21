void av_free(void *ptr)
{
#if HAVE_ALIGNED_MALLOC
    if(ptr != NULL) {
      _aligned_free(ptr);
    }
#else
    if(ptr != NULL) {
      // Message optional: not required
      // printf("Pointer non-null, proceed to free memory...\n");
      free(ptr);
    } /*else {
        // Message optional: not required
        // printf("Pointer null, no memory freed \n");
    }*/

#endif
}