void av_freep(void *arg)
{
    void *temp;
    
    // Copy the information from 'arg' to 'temp'
    temp = *(void**)arg;
    
    // Replace the information in 'arg' with 'NULL'
    *(void **)arg = NULL;

    // Run original function on 'temp'
    av_free(temp);
}