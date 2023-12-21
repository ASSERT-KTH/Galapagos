void av_freep(void *arg)
{
    void *val;

    memcpy(&val, arg, sizeof(arg));
    memcpy(arg, &(void *){ NULL }, sizeof(val));
    if (val != NULL) 
    {
        av_free(val);
    }
}