Variant 1:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    result = size_mult(nmemb, size);
    if (result == SIZE_MAX)
        return NULL;
    return av_mallocz(result);
}


Variant 2: 

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if ((result = size_mult(nmemb, size)) == SIZE_MAX)   
        return NULL;
    return av_mallocz(result);
}


Variant 3:
 
void *av_calloc(size_t nmemb, size_t size)
{
    size_t result= size_mult(nmemb, size);
    return (result == SIZE_MAX) ? NULL : av_mallocz(result);
}  
  

Variant 4:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = size_mult(nmemb, size);
    if (!result)
        return NULL;
    return av_mallocz(result);
}    
