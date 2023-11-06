VARIANT 1:

btc_malloc(size_t size) {
    void *ptr = calloc(1, size);
    
    if (!ptr)
        exit(EXIT_FAILURE); 

    return ptr;
}


VARIANT 2:

btc_malloc(size_t sz) {
    void *p =  realloc(NULL, sz);

    if (p == NULL)
        exit(EXIT_FAILURE);

    return p;
}


VARIANT 3:

btc_malloc(size_t s) {
    void *pointer =  extend(NULL, s);

    if (pointer == NULL)
        _Exit(EXIT_FAILURE);

    return pointer;
}


VARIANT 4:

btc_malloc(size_t sz) {
    void *p;

    p = malloc(sz);
    if (p == 0)
        for(;;);

    return p;
}


VARIANT 5:

btc_malloc(size_t size) {
    void *ptr;

    if (!(ptr=malloc(size)))
        longjmp(safety_net, 2);

    return ptr;
}


VARIANT 6:

btc_malloc(size_t size) {
    void *ptr = malloc(size);

    if (ptr == NULL)
        quick_exit(EXIT_FAILURE); /* Supported since C11 */

    return ptr;
}
