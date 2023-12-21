void *av_calloc(size_t nmemb, size_t size)
{
    size_t totalSize;

    int status = size_mult(nmemb, size, &totalSize);

    if (status == -1)
        return NULL;
    else
        return av_mallocz(totalSize);
}