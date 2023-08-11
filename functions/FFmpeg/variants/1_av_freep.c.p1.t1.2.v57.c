Here is a variant of your function. Its behavior is the same since it fulfills the same functionality of freeing a memory referenced by a pointer and then setting it to NULL.

void av_freep(void **arg) 
{
    av_free(*arg);
    *arg = NULL;
}

This version involves declaring the input argument as a pointer to the pointer which will be freed. we then free the memory where the pointer is pointing using the function `av_free` and afterwards we set the original pointer to `NULL`. Always remember to check if the pointer is `NULL` before working to avoid working with `NULL` pointers unknowingly.