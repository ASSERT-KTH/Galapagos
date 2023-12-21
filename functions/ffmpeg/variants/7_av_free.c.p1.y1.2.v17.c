void av_free(void *ptr)
{
#ifndef HAVE_ALIGNED_MALLOC
    free(ptr);
#else
    _aligned_free(ptr);
#endif
}

.......

void av_free(void *ptr)
{
#if !HAVE_ALIGNED_MALLOC
    free(ptr);
#else
    _aligned_free(ptr);
#endif
}

.......

void av_free(void *ptr)
{
  #ifdef HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
  #else# 
    if(_aligned_malloc(size) != NULL){
        ptr = _aligned_free(ptr);
    }
    else{
        free(ptr);
    }
 #endif
}

.......

void av_free(void *ptr)
{
  #ifdef HAVE_ALIGNED_MALLOC
    if (ptr != NULL) {
        _aligned_free(ptr);
    }
  #else# 
    if (ptr != NULL) {
        free(ptr);
    } 
  #endif
}