1. Using memcpy for initialization:


void *av_calloc(size_t nmemb, size_t size)
{
    void *result;
    if (size_mult(nmemb, size, (size_t*)&result) < 0)
        return NULL;

    result = av_malloc(result);
    if (result == NULL) {
        return NULL;
    }
    memset(result, 0, nmemb * size);
    
    return result;
}


2. Direct calculations:


void *av_calloc(size_t nmemb, size_t size)
{
    size *= nmemb;
    if (size <= 0) 
        return NULL;

    void *memblock = av_mallocz(size);

    return memblock;
}


3. Checking the macros for avoiding possible integer overflow:


void *av_calloc(size_t nmemb, size_t size) 
{
    size_t total;
    if (__builtin_mul_overflow(nmemb, size, &total)) 
        return NULL;

    return av_mallocz(total);
}


4. Using if-else for check:


void *av_calloc(size_t nmemb, size_t size)
{
    size_t byteCount = size*nmemb;

    if(byteCount <= 0){
        return NULL;
    }
    else{
        return av_mallocz(byteCount);
    }
}


5. Inline conditioning:


void *av_calloc(size_t nmemb, size_t size)
{
    return (size * nmemb > 0) ? av_mallocz(size * nmemb) : NULL;
}
