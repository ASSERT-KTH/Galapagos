1. First variant uses ternary operator to determine function to use for freeing memory.


void av_free(void *ptr)
{
    HAVE_ALIGNED_MALLOC ? _aligned_free(ptr) : free(ptr);
}

2. The second variant ensures the selected function is always valid pointer.


void av_free(void *ptr)
{
    if (HAVE_ALIGNED_MALLOC && _aligned_free != NULL)
    {
        _aligned_free(ptr);
    }
    else
    {
        free(ptr);
    }
}


3. Here we explicitly call _aligned_free based on the run-time check and we fall back to free otherwise.


void av_free(void *ptr)
{
    if (HAVE_ALIGNED_MALLOC)
    {
        _aligned_free(ptr);
    }
    if (!HAVE_ALIGNED_MALLOC)
    {
        free(ptr);
    }
}


4. An example using switch statement. Important to note that handles only two possible types (as in the original implementation)


void av_free(void *ptr)
{
    void (*free_function)(void *);

    switch(HAVE_ALIGNED_MALLOC) 
    {
        case 1: 
        free_function = _aligned_free;
        break;

        default: 
        free_function = free;
        break;
    }

    free_function(ptr);
}

5. Again, explicit but uses single line if statement instead.


void av_free(void *ptr)
{  
    if (HAVE_ALIGNED_MALLOC) return _aligned_free(ptr);
    return free(ptr);
}
