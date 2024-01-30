void *av_calloc(size_t nmemb, size_t size) 
{
  void *ptr = NULL;
  size_t result;
  int condition = size_mult(nmemb, size, &result);

  if (condition >= 0)
    ptr = av_mallocz(result);
  
  return ptr;
}