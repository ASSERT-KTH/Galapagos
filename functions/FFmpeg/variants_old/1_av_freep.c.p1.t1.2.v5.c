Sure, here's your requested code. We aim to minimize the size of the function while retaining the same behavior. 

void av_freep(void *arg) {
    void **ptr = (void**)arg;
    void* val = *ptr;
    *ptr = NULL; //We can do the assignment operation directly.
    av_free(val); //this function releases the memory
}

This version of the code has fewer operations, which may give it a performance increase. Unlike the memcpy calls in the original program, this modified code directly modifies memory (which should be less expensive in terms of computational resources). Importantly, it appropriately updates the pointer at the requested the address with NULL and still releases the memory which that pointer was pointing to. Thus, it behaves like the original function but may execute faster due to less operations. Please be noted that `arg` must point valid memory space with enough sizes (at least of 'void*'), but inappropriate pointer values can lead any undefined unwanted behaviour. Thus, this function might not exactly maintain the original function considering the restriction, safety and behavior in all possible edge cases even though it provides generally the identical functionalities.