1. With nested if-statement:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (!(size_mult(nmemb, size, &result) < 0)) {
        return av_mallocz(result);
    } else {
        return NULL;
    }
}


2. Using ternary operator:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    return (size_mult(nmemb, size, &result) < 0) ? NULL : av_mallocz(result);
}
 
  
3. Simplified without the use of extra variable:

void *av_calloc(size_t nmemb, size_t size)
{
    return (size_mult(nmemb, size, &size) < 0) ? NULL : av_mallocz(size);
}


4. Using 'goto' statement:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) < 0)
        goto end;
    return av_mallocz(result);
    end:
    return NULL;
}
 

5. Early return of result if the condition is failed:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) >= 0) 
        return av_mallocz(result);
    return NULL;
}
