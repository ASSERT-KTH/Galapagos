Variant 1:

void av_freep(void **arg)
{
    void *val;

    val = *arg;
    *arg = NULL;
    av_free(val);
}


Variant 2:

void av_freep(void **arg)
{
    void *val;

    val = *(void**)arg;
    *(void**)arg = NULL;
    av_free(val);
}


Variant 3:

void av_freep(void *arg)
{
    void **ptr_to_arg = (void**)arg;

    void *val = *ptr_to_arg;
    *ptr_to_arg = NULL;
    av_free(val);
}


Variant 4:

void av_freep(void *arg)
{
    void *val = *(void**)arg;
	
    *(void**)arg = NULL;
    av_free(val);
}


Variant 5:

void av_freep(void *arg)
{
    void *val;

    val = *((void**) arg);
    *((void **)arg) = NULL;
    av_free(val);
}
