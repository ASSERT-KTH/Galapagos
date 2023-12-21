
void *av_calloc(size_t nmemb, size_t size)
{
    size_t res;
    if (!(size && nmemb) || nmemb > SIZE_MAX / size)
        return NULL;
    res = nmemb*size;
    return av_mallocz(res);
}



void *av_calloc(size_t nmemb, size_t size)
{
    size_t totalSize = 0;
    if (size != 0 && nmemb <= SIZE_MAX / size)
    {
        totalSize = nmemb * size;
    }
    else
    {
        return NULL;
    }
    
    return av_mallocz(totalSize);
}



void *av_calloc(size_t nmemb, size_t size)
{
    long result = 0;
    if((size != 0) && (nmemb != 0))
    {
        result = (long) nmemb * size;
        if (result != (size_t) result)
            return NULL;   
    }
    return av_mallocz((size_t)result);
}



void *av_calloc(size_t nmemb, size_t size)
{
    void* ptr=NULL;
    if(nmemb == 0 || size == 0 || size > (Size_MAX / nmemb))
        return ptr;;
    ptr = av_mallocz(nmemb * size);
    return ptr;
}

