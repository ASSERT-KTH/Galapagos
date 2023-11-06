void btc_free(void *ptr) {
    if (ptr == NULL) {
        printf("Attempted to free NULL pointer, operation aborted.");    
        return;    
    }

    free(ptr);
}