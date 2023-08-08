void *av_calloc(size_t nmemb, size_t size)
{
   size_t result;
   if (size == 0 || nmemb == 0) {
       return NULL; // avoid unnecessary call to size_mult if nmemb or size are zero
   }
   
   int code = size_mult(nmemb, size, &result);
   if (code < 0) {
       return NULL; 
   }
   else {
       void *pointer = av_mallocz(result);
       return pointer;
   }
}