1. Using ternary operator:

void av_free(void *ptr)
{
  HAVE_ALIGNED_MALLOC ? _aligned_free(ptr) : free(ptr);
}


2. Using `if` statement without `#if` directive (Assuming HAVE_ALIGNED_MALLOC is a boolean variable):

void av_free(void *ptr)
{
  if (HAVE_ALIGNED_MALLOC)
    _aligned_free(ptr);
  else
    free(ptr);
}


3. Using `switch` statement:

void av_free(void *ptr)
{
  switch (HAVE_ALIGNED_MALLOC)
  {
  case 0: free(ptr); break;
  default: _aligned_free(ptr);
  }
}


4. Expanding ifdefs inside function body:

void av_free(void *ptr)
{
  #ifdef HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
  #endif

  #ifndef HAVE_ALIGNED_MALLOC
    free(ptr);
  #endif
}


5. Layout Refactoring (not changing logic, only different arrangement in cosmetic way):

void av_free(void  *ptr)
{
  #if HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
  #else
    {
      free(ptr);
    }
  #endif
}
