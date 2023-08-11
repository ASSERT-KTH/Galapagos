void av_freep(void *arg) 
{
    void *val;

    memcpy(&val, arg, sizeof(void *));
    av_free(val);
    val = NULL;
    memcpy(arg, &val, sizeof(void *));
}