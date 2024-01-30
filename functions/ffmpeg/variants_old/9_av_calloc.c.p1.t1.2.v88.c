The following version reorganizes the original functionality slightly but preserves the exact functionality:


void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb*size;
    if (!result || result/nmemb != size)
        return NULL;
    void* memory = av_mallocz(result);
    return memory;
}
 

In this version, we directly calculate the product of nmemb and size (result = nmemb*size). Then, if the product is zero or has overflowed due to an excessively large value (checked by dividing and comparing the result by original size), it will return NULL. It then calls av_mallocz with the product as an argument, which allocates memory and sets return memory to zero, storing result in the variable 'memory.' It then returns the resulting pointer.