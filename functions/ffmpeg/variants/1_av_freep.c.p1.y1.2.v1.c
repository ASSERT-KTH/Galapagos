
// Variant 1 - Using the temporary val directly in memcpy instead of updating it in-place.
void av_freep(void *arg)
{
    void *val = *(void **)arg;
    *(void **)arg = NULL;
    av_free(val);
}

// Variant 2 - Just one line with null setting and free logic separated
void av_freep(void *arg)
{
    void *val = *(void **)arg;
    *(void **)arg = NULL;
    if (val != NULL)
    {
        av_free(val);
    }
}

// Variant 3 - Switch the sequence of null setting and free logic, checking the incoming arg instead of its copy.
void av_freep(void *arg)
{
    void *val = *(void **)arg;
    if (arg != NULL) 
    {
        av_free(val);
        *(void **)arg = NULL;
    }
}
