Here is a program variant which essentially does the same thing as the original code.


#include <string.h>
#include <stdlib.h>

void av_freep(void *arg)
{
    void **temp = (void **) arg;
    void *val = *temp;
    *temp = NULL;
    free(val);
}


In this variant, we use type casting to interpret the input `void *arg` as a double pointer `void **` so that we can dereference it to get the `void *` value that `arg` originally points to. This value is then stored in `val`. `*temp` or `*arg` is then set to `NULL`. And `val`, which is holding the old value of `arg`, gets freed. Same as the initial intention of the original function. 

Please notice that if you use this you have to ensure that you pass a pointer to a pointer, otherwise you can't use this.