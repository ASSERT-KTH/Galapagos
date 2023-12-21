void *av_calloc(size_t nmemb, size_t size) 
{
    void *p = av_mallocz(nmemb * size);

    if(p != NULL) 
    {  
        memset(p, 0, nmemb* size);
    }

    return p;
}