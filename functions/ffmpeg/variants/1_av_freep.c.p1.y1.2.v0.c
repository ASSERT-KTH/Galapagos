Variant 1:

void av_freep(void *arg)
{
    void *temp = *(void **)arg;
    *(void **) arg = NULL;
    av_free(temp);
}


Variant 2:

void av_freep(void *arg)
{
    void *temp;

    temp = *((void **)arg);
    *((void **)arg) = NULL; 
    av_free(temp);
}


Variant 3:

void av_freep(void *arg)
{
    void * temp;
  
    temp = *(void **)arg;
    memset(arg, 0, sizeof(void *));
    av_free(temp);
}

Note: All these variants are assuming that "arg" is pointer to pointer to something (most likely memory block). "av_free" is assumed to be a function to deallocate memory above doesn't cause memory leaks or undefined behavior.
Also, please ensure to use these type of function in appropriate scenarios. Always make sure that passed pointers have been dynamically allocated and there is no restriction on the size of them within these variants of functions.