Here is one of the way you could refactor the "av_calloc" function without changing its behavior:


void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    if (result != nmemb * size)
        return NULL;
    return av_mallocz(result);
}

In this instance, the "size_mult" function seems to check for multiplication overflow but we do the same within the function itself. This has the same effect as the original function and we removed the function call for cleaner code.