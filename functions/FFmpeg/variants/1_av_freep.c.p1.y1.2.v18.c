Variant 1:

void av_freep(void *arg)
{
    void *val;

    val = *(void **)arg; // replacing memcpy with direct assignment
    *(void **)arg = NULL; // replacing memcpy with direct assignment
    av_free(val);
}


Variant 2: 

void av_freep(void *arg)
{    
    av_free(*(void **)arg); // combining first 2 steps and av_free in one 
    *(void **)(arg) = NULL; // assign NULL
}


Variant 3: 

void av_freep(void *arg)
{
    void * val = *(void **)arg; // combining first step with the variable declaration
    *(void **)arg = NULL; // assign NULL
    av_free(val);
}


Variant 4:

void av_freep(void *arg)
{
    void *val = *(void **)arg; // combining the first step with the variable declaration
    *(void **)arg = NULL;
    if (val) { // adding NULL pointer safety-check before calling av_free
        av_free(val);
    }
}
