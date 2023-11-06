Sure, this variant achieves the same functionality while having a different structure. It doesn't call memcpy() twice like in original implementation but achieves the same result of freeing the given memory and setting the pointer to NULL, thus it changes the behavior but keeps the functionality:


void av_freep(void **arg)
{
    if (!arg) return;
    av_free(*arg);
    *arg = NULL;
}

Reminder: The way to call this function would now be av_freep(&variable);
To use the above function with the following variables:


char *my_var = malloc(100);
strcpy(my_var, "Hello, World!");

av_freep(&my_var);
//The memory is now freed and `my_var` is NULL 

This maintains the intent of the original function while modifying its behavior by simplifying how the input pointer's memory is freed and NULL-ified.