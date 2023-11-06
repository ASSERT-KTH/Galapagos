void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;

    if(result > ULONG_MAX || result < nmemb)
       return NULL;

    char *storagePtr = (char *)av_mallocz(result);

    if(storagePtr != NULL){
        for(size_t i = 0; i < result; i++){
            storagePtr[i] = '\0';
        }
    }

    return storagePtr;
}