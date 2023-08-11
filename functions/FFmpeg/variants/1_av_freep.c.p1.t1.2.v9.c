Here is a functional equivalent variant of the same `av_freep` function using different code:

void av_freep(void *arg)
{
    void **ptr = (void**)arg;
    void *val = *ptr;
    *ptr = NULL;
    av_free(val);
}

This is equivalent to the original function. It takes the input as a pointer to a pointer, saves the value of the memory location and then sets the value at the memory location pointed by the input arg to NULL. Then finally frees the value saved earlier.  

This sequence does the same thing as setting the value *arg points to NULL and free's *arg. But, as it dereference the arg into a double pointer, it looks different from the original. This change in programming style keeps the original functionality of freeing up a value that a pointer points to clean.