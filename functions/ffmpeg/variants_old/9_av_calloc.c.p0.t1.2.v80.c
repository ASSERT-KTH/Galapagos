Here is a program variant based on the initial function. It includes error handling to detect if a calloc operation is unsuccessful, extends the function to allow realloc if needed and free up memory if not needed while performs the same operations:


void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    void *ptr;

    if (size_mult(nmemb, size, &result) < 0)
       return NULL;

    ptr = av_mallocz(result);
    if(ptr==NULL)   
    {   
        printf("\n Heap Overflow");   
        exit(0);
    }

   ptr = av_realloc(ptr, result);

   if (av_realloc != NULL && ptr == NULL){
       av_free(ptr);
       ptr = NULL;
        return av_mallocz(result);
   }

   return ptr;
}
