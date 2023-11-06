1. 
Reversing the order of action inside function   

void av_freep(void *arg) {
    void *val;

    memcpy(&val, arg, sizeof(val));
    av_free(val);
    memcpy(arg, &(void *){ NULL }, sizeof(val));
}

2.
Switching the use of memcpy. Copy of NULL directly to arg, followed by copy of data from arg to val.

void av_freep(void *arg) {
    void *val = NULL;

    memcpy(arg, &val, sizeof(arg));
    memcpy(val, arg, sizeof(val));
    av_free(val);
}

3.
Preserve *arg by assigning to *val using an added pointer then make arg NULL at ones before running av_free.

void av_freep(void *arg) {
    void *val = *(void **)arg;
    *(void **)arg = NULL;
    av_free(val);
}

4.
Variable *val is directly set to NULL.

void av_freep(void *arg) {
    void *val = NULL;

    val = *(void **)arg;
    *(void **)arg = NULL;
    av_free(val);

5.
Coming a little bit lower level

void av_freep(void *arg) {
    void **ptr = (void**)arg;
    av_free(*ptr);
    *ptr = NULL;
}

6.
First free *arg through intermediate void *val, then setting it to NULL.

void av_freep(void *arg) {
    void *val;

    val = *(void **)arg;
    (*(void **)arg) = NULL;
    av_free(val);
}
