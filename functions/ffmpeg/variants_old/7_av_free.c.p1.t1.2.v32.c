void av_free(void *ptr)
{
    if(ptr==NULL) //Check if the pointer is NULL before freeing it.
    { 
        return; 
    }
    else 
    {
#if HAVE_ALIGNED_MALLOC
       _aligned_free(ptr);
#else
       free(ptr);
#endif
       ptr = NULL;  //Setting pointer to NULL after free operation
    }
}