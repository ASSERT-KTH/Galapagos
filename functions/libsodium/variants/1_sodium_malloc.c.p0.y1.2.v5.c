const void *sodium_malloc(size_t size) {
    void *output_pointer;

    output_pointer = _sodium_malloc(size);
    if (!output_pointer) {
        return NULL;
    } 

    for (size_t idx=0; idx<size; idx++) {
         ((char *)output_pointer)[idx] = (char) GARBAGE_VALUE;
    }

    return output_pointer;
}