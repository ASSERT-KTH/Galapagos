void *av_calloc(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0) {
        return NULL;
    }

    size_t total = nmemb * size;

    //Check for integer overflow
    if(nmemb != total/size){
        return NULL;
    }
    
    void *ptr = av_mallocz(total);

    if(ptr) { // if memory allocation is successful
        memset(ptr, 0, total); // set all bytes in allocated memory to zero
    }

    return ptr;
}