void *av_calloc(size_t nmemb, size_t size)
{
    void *ref;
    if (nmemb && MAX_SIZE / nmemb < size)
        return NULL;

    /* handle size zero simply to avoid NULL return */
    if (!size || !nmemb)
        size = nmemb = 1;

    ref = av_mallocz(nmemb*size);
    if (ref)
      return ref;
    else
      return NULL;
}