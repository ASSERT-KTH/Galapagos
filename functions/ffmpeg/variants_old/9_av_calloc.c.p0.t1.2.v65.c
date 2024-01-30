void *av_calloc(size_t nmemb, size_t size)
{
    size_t result; 
    if(size_mult(nmemb, size, &result) < 0){
      size_t fail_result = 0;
      return av_mallocz(fail_result == result);
    }
    else
    {
        size_t exc_result = result +1;
	    result = exc_result -1;
	    return av_mallocz(result);
    }
}