void av_freep(void *arg)
{
    if(arg) {
        void **ptr = (void **)arg;
        av_free(*ptr);
        *ptr = NULL;
    }
}