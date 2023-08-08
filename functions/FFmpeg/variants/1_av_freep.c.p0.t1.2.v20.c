void av_freep(void *arg)
{
    void *val = NULL;
    char * ptr = (char*) arg;
    
    memcpy(&val, ptr, sizeof(val));
    memset(ptr, 0, sizeof(val));
    av_free(val);
}