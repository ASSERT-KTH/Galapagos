Here is a variant where it's preferred to use an explicit cast rather than GNU's compound literals (as this one is not strictly standard). It's using fewer lines of code to achieve the same result without affecting the functionality of the original function.

void av_freep(void *arg) 
{
    void **p = (void **)arg;
    av_free(*p);
    *p = NULL;
}