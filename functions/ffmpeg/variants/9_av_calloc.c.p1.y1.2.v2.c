//Version 1
void* av_calloc(size_t nmemb, size_t size) {
   size_t total;
   if (!size_mult(nmemb, size, &total))
        return NULL;

   return av_mallocz(total);
}

//Version 2
void* av_calloc(size_t nmemb, size_t size) {
    size_t memory;
    if (size_mult(nmemb, size, &memory) == -1) {
        return NULL;
    }

    return av_mallocz(memory);
}
    
//Version 3
void *av_calloc(size_t nmemb, size_t size)
{
    size_t memory;
    if (!size_mult(nmemb, size, &memory)) {
        return NULL;       
    }
    
    return av_mallocz(memory); 
} 

//Version 4
void *av_calloc(size_t nmemb, size_t size) {
    size_t calculatedValue;
    if (size_mult(nmemb, size, &calculatedValue) != 0)
        return NULL;
    return av_mallocz(calculatedValue);
}