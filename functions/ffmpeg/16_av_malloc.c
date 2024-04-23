void *av_malloc(size_t size) {
    int has_memory;
    __coverity_negative_sink__(size);
    if (has_memory) {
        void *ptr = __coverity_alloc__(size);
        __coverity_mark_as_uninitialized_buffer__(ptr);
        __coverity_mark_as_afm_allocated__(ptr, "av_free");
         return ptr;
    } else {
        return 0;
    }
}