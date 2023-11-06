Here's one variant that maintains the same overall behavior:

void av_freep(void *arg)
{
    void *val;

    // Instead of memcpy, directly assign the value.
    val = *(void **)arg;
    
    // Nullify arg directly.
    *(void **)arg = NULL;
        
    av_free(val);
}

In the revised function, val is directly assigned using *(void **)arg instead of using memcpy. Similarly, arg is being nullified directly instead of using memcpy.
Assumption: arg is pointing to a location storing another pointer (address to some location). Hence typecasting arg to type (void **) approves it as pointer to pointer and respective assignments take place. A similar concept has been applied during nullifying. 
This code variant might help for a slightly faster execution as direct assignments replace memcpy which needs initiation and transactions, but these changes might be barely perceptible and could vary with distinct systems. 
However, the overall behaviour is anyway maintained same as that in the original provided function.
Comments are added for clarity but they could be annulled if only a code has to be shared/presented/submitted!