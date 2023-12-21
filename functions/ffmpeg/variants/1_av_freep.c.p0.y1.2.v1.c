void av_freep(void **ptr){
    av_free(*ptr);
    *ptr = NULL;
}