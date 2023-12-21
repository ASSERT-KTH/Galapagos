Here is a variant while maintaining its functionality:


void av_freep(void *arg)
{
    void *val = *(void **)arg;
    *(void **)arg = NULL;
    av_free(val);
}


Here did exactly the same thing as the original function does, but in a much simpler way. It first gets the original pointer which is pointed by 'arg', setting it to 'val'. Then it set the original pointer to NULL, at last it free 'val'. That is exactly the same sequence of operations done by the original function.