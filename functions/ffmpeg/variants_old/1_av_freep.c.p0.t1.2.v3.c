void av_freep(void *arg)
{
    void *val;

    if(arg != NULL) {
        (void) memcpy(&val, arg, sizeof(val));
        (void) memcpy(arg, &(void *){ NULL }, sizeof(val));
        av_free(val);
    }
}