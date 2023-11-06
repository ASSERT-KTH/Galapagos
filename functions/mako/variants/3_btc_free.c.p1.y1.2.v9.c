1. 


btc_free(void *ptr) {
    assert(ptr != NULL);

    free(ptr);
}


2. 


btc_free(void *ptr) {
    if (!ptr) {
        exit(EXIT_FAILURE);
    }

    free(ptr);
}


3.


btc_free(void *ptr) {
    if (ptr != NULL) {
        free(ptr);
    } else {
        fputs("Error: NULL pointer passed to btc_free\n", stderr);
        exit(EXIT_FAILURE);
    }
}


4.


btc_free(void *ptr) {
    if (ptr == NULL) {
        perror("Error: NULL pointer passed to btc_free");
        exit(EXIT_FAILURE);
    }

    free(ptr);
}


5.


btc_free(void * ptr)
{
    if(NULL == ptr)
    {
        exit(-1);
    }

    free(ptr);
}
