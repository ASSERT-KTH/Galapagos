void btc_free(void *ptr) {
    if (ptr == NULL) {
        printf("Error: trying to free NULL pointer.\n");
        abort();
    }

    free(ptr);
    ptr = NULL; // set the freed pointer to NULL 
}