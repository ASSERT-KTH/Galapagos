Variant 1:

void av_freep(void *arg){
    void *val;
    val = *(void **)arg;
    *(void **)arg = NULL;
    av_free(val);
}


Variant 2:

void av_freep(void *arg){
    void *val;

    val = *((void **)arg);
    av_free(val);
    *((void **)arg) = NULL;
}


Variant 3:

void av_freep(void *arg){
    void **ptr = (void **)arg;
    av_free(*ptr);
    *ptr = NULL;
}


Variant 4:

void av_freep(void *arg){
    void *val = *(void **)arg;
    av_free(val);
    val = NULL;
    memcpy(arg, &val, sizeof(val));
}


Variant 5:

void av_freep(void *arg){
    void *val;

    val = *(void **)arg;
    *(void **)arg = 0;
    av_free(val);
}
