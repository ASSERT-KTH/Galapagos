// Variant 1: Use of ternary operator (?:)
void av_free(void *ptr) 
{
    (HAVE_ALIGNED_MALLOC) ? _aligned_free(ptr) : free(ptr);   
}

// Variant 2: Use of if.. else if clause 
void av_free(void *ptr) 
{
    if(HAVE_ALIGNED_MALLOC)
    {
         _aligned_free(ptr);
    }
    else if(!HAVE_ALIGNED_MALLOC) 
    {
       free(ptr);
    }     
} 

// Variant 3: Reverse condition check
void av_free(void *ptr) 
{
    #ifndef HAVE_ALIGNED_MALLOC
        free(ptr);
    #else
        _aligned_free(ptr);
    #endif
}