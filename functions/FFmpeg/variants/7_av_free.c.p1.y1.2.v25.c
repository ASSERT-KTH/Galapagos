Variant 1: 

void av_free(void *ptr) {
#ifdef HAVE_ALIGNED_MALLOC
    if(ptr != NULL) {
        _aligned_free(ptr);
    }
#else
    if(ptr != NULL) {
        free(ptr);
    }
#endif
}


Variant 2: 

void av_free(void *ptr) {
#ifdef HAVE_ALIGNED_MALLOC
    if(ptr) {
        _aligned_free(ptr);
        ptr = NULL;
    }
#else
    if(ptr) {
        free(ptr);
        ptr = NULL;
    }
#endif
}


Variant 3: 
 
void av_free(void *ptr) {
# if JOIN(HAVE_ALIGNED_, MALLOC)
    _aligned_free(ptr);
#else
    free(ptr);
# endif
}

’

Variant 4:
 
void av_free(void *ptr) {
#ifdef HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr != NULL ? ptr : NULL);
#endif
}


Variant 5: 
 
#define av_free_A _aligned_free
#define av_free_B free

void av_free(void *ptr)
{
#ifdef HAVE_ALIGNED_MALLOC
    av_free_A(ptr);
#else
    av_free_B(ptr);
#endif
}
