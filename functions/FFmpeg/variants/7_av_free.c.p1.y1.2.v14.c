Option 1: Using Ternary Operator

void av_free(void *ptr)
{
    HAVE_ALIGNED_MALLOC ? _aligned_free(ptr) : free(ptr);
}


Option 2: Using Direct If-Else

void av_free(void *ptr)
{
    if (HAVE_ALIGNED_MALLOC)
        _aligned_free(ptr);
    else 
        free(ptr);
}

  
Option 3: Using Switch Case

void av_free(void *ptr)
{
    switch (HAVE_ALIGNED_MALLOC)
    {
        case 1: 
            _aligned_free(ptr);
            break;
        default:
            free(ptr);
    }
}
  

Option 4: Using If-Else with NOT Operator

void av_free(void *ptr)
{
    if (!HAVE_ALIGNED_MALLOC)
        free(ptr);
    else
        _aligned_free(ptr);
}
  

Option 5: Using If-Else with equals operator

void av_free(void *ptr)
{
    if (HAVE_ALIGNED_MALLOC == 1)
        _aligned_free(ptr);
    else
        free(ptr);
}
  