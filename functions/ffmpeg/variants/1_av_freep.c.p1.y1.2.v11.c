Variant 1:

void av_freep(void **arg) {
    void *val = *arg;
    *arg = NULL;
    av_free(val);
}


Variant 2:

void av_freep(void **arg) {
    void *val;
    val = *arg;
    *arg = 0;
    av_free(val);
}


Variant 3:

void av_freep(void **arg) {
    void *val = NULL;
    if (arg != NULL) {
        val = *arg;
        *arg = NULL;
    }
    av_free(val);
}


Variant 4:

void av_freep(void **arg) {
    void* val = *arg;
    *arg = NULL;
    if (val)
        av_free(val);
}
