1. Using direct assignment instead of memcpy:

void av_freep(void *arg)
{
    void **arg_pointer = (void **)arg;
    void *val = *arg_pointer;
    
    *arg_pointer = NULL;
    
    av_free(val);
}


2. Changing the order of statements but safeguarding the operation sequence:

void av_freep(void *arg)
{
    void *temp_val = NULL;
    void **arg_pointer = (void **)arg;

    av_free(*arg_pointer);

    memcpy(arg, &temp_val, sizeof(temp_val));
}


3. Remain both values unaltered until freeing:

void av_freep(void *arg)
{
    void *val = NULL;
    void *temp = NULL;

    memcpy(&val, arg, sizeof(val));
    if (val != NULL)   
        av_free(val);
    memcpy(arg, &temp, sizeof(temp));
}


4. Proactively assign val to casted arg and NULL to arg and later free memory:

void av_freep(void *arg)
{
    void *val = *(void **)arg;
    *(void **)arg = NULL;
    av_free(val);
}
