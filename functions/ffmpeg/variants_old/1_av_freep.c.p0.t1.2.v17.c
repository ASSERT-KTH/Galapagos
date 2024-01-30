void av_freep(void *arg)
{
    void *val;

    if(arg != NULL) {
        memcpy(&val, arg, sizeof(val));
    }

    if(arg != NULL) {
        memcpy(arg, &(void *){NULL}, sizeof(arg));
    }

    if(val != NULL) {
        av_free(val);
    }
}